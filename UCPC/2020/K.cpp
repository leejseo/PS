#include <bits/stdc++.h>
using namespace std;

struct vect { 
    double x;
    double y;
    vect() { x = y = 0; }
    vect(double x, double y) {
        this->x = x;
        this->y = y;
    }
    const double dist() const { // 거리
        return sqrt(x * x + y * y);
    }
    const double inner(const vect &a) const { // 내적
        return x * a.x + y * a.y;
    }
    const double cross(const vect &a) const { // 외적(determinant)
        return x * a.y - y * a.x;
    }
    const vect operator+ (const vect &a) const { // 벡터의 합
        return vect(x + a.x, y + a.y);
    }
    const vect operator- (const vect &a) const { // 벡터의 차
        return vect(x - a.x, y - a.y);
    }
    const vect operator* (const double &a) const { // 스칼라 곱
        return vect(a * x, a * y);
    }
    const vect proj(const vect &a) const { // projection vector
        return *this * (inner(*this) / inner(a));
    }
    const double get_cos(const vect &a) const { // 두 벡터의 코사인
        return inner(a) / (dist() * a.dist());
    }
};

struct edg {
    int a;
    int b;
    edg() { a = b = 0; }
    edg(int a, int b) {
        if(a < b) {
            this->a = a;
            this->b = b;
        }
        else {
            this->a = b;
            this->b = a;
        }
    }
    const bool operator== (const edg &x) const {
        return a == x.a && b == x.b;
    }
    const bool operator< (const edg &x) const {
        if(a == x.a) return b < x.b;
        return a < x.a;
    }
};

struct tri { 
    int a;
    int b;
    int c;
    tri() { a = b = c = 0;}
    tri(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

bool is_circum(tri cur, int i, vector<vect> &point) { 
    double ccw = (point[cur.b] - point[cur.a]).cross(point[cur.c] - point[cur.a]);

    double adx=point[cur.a].x-point[i].x, ady=point[cur.a].y-point[i].y,
    bdx=point[cur.b].x-point[i].x, bdy=point[cur.b].y-point[i].y,
    cdx=point[cur.c].x-point[i].x, cdy=point[cur.c].y-point[i].y,
    bdxcdy = bdx * cdy, cdxbdy = cdx * bdy,
    cdxady = cdx * ady, adxcdy = adx * cdy,
    adxbdy = adx * bdy, bdxady = bdx * ady,
    alift = adx * adx + ady * ady,
    blift = bdx * bdx + bdy * bdy,
    clift = cdx * cdx + cdy * cdy;
    double det = alift * (bdxcdy - cdxbdy)
    + blift * (cdxady - adxcdy)
    + clift * (adxbdy - bdxady);
    
    if(ccw > 0) return det >= 0;
    else return det <= 0;
}

int V, E, F;

int par[3005];

void init(){
    for (int i=0; i<=3004; i++) par[i] = i;
}

int root(int x){
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

void merge(int u, int v){
    u = root(u);
    v = root(v);
    if (u != v) par[u] = v;
}

vector<vect> ans;
vector<pair<int, int>> edges;

set<pair<int, int>> used;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E >> F;
    int C = V - E + F;
    int N = V - C + 1;
    int M = E, K = F;
    init();
    if (N < 3){
        if (N == 1) ans.push_back(vect(1, 1));
        else if (N == 2){
            ans.push_back(vect(1, 1));
            ans.push_back(vect(1, 2));
            edges.push_back({1, 2});
        }
    }
    else{
        int n = N - 3;
        vector<vect> point(n+3);
        int cnt = 0;
        for (int s=4; s<=80; s++){
            if (cnt == n) break;
            for (int i=2; i<=78; i++){
                int j = s - i;
                if (j < 2) break;
                point[cnt++] = vect(i, j);
                if (cnt == n) break;
            }
        }
        point[n] = vect(1, 1);
        point[n+1] = vect(1, 79);
        point[n+2] = vect(79, 2);
        for (auto p: point){
            ans.push_back({(int)p.x, (int)p.y});
        }
        vector<tri> triangle;
        triangle.push_back(tri(n, n + 1, n + 2));
        for(int i = 0; i < n; i++) {
            set<edg> polygon;
            vector<int> complete(triangle.size(), 0);
            for(int j = 0; j < triangle.size(); j++) {
                if(complete[j]) continue;
                tri cur = triangle[j];
                if(is_circum(cur, i, point)) {
                    if(polygon.count(edg(cur.a, cur.b))) polygon.erase(edg(cur.a, cur.b)); // 만약 겹치는 edge라면 제거
                    else polygon.insert(edg(cur.a, cur.b)); // 안 겹치면 삽입
                    if(polygon.count(edg(cur.b, cur.c))) polygon.erase(edg(cur.b, cur.c));
                    else polygon.insert(edg(cur.b, cur.c));
                    if(polygon.count(edg(cur.c, cur.a))) polygon.erase(edg(cur.c, cur.a));
                    else polygon.insert(edg(cur.c, cur.a));
                    
                    swap(complete[j], complete[triangle.size() - 1]); // bad triangle 은 제거한다.
                    swap(triangle[j], triangle[triangle.size() - 1]);
                    triangle.pop_back();
                    j--;
                    continue;
                }
                complete[j] = true;
            }
            for(auto &cur : polygon) {
                if((point[cur.b] - point[cur.a]).cross(point[i] - point[cur.a]) == 0) continue; // 일직선이므로 삼각형이 될 수 없다. 따라서 무시
                triangle.push_back(tri(cur.a, cur.b, i));
            }
        }
        for (auto T: triangle){
            int a = T.a, b = T.b, c = T.c;
            if (root(a) != root(b)){
                merge(a, b);
                edges.push_back({a, b});
                used.insert({a, b});
                used.insert({b, a});
            }
            if (root(b) != root(c)){
                merge(b, c);
                edges.push_back({b, c});
                used.insert({c, b});
                used.insert({b, c});
            }
            if (root(c) != root(a)){
                merge(c, a);
                edges.push_back({c, a});
                used.insert({c, a});
                used.insert({a, c});
            }
        }
        for (auto T: triangle){
            if (edges.size() >= M) break;
            int a = T.a, b = T.b, c = T.c;
            if (!used.count({a, b})){
                used.insert({a, b});
                used.insert({b, a});
                edges.push_back({a, b});
                if (edges.size() >= M) break;
            }
            swap(a, c);
            if (!used.count({a, b})){
                used.insert({a, b});
                used.insert({b, a});
                edges.push_back({a, b});
                if (edges.size() >= M) break;
            }
            swap(b, c);
            if (!used.count({a, b})){
                used.insert({a, b});
                used.insert({b, a});
                edges.push_back({a, b});
                if (edges.size() >= M) break;
            }
        }
    }
    C--;
    int cnt = 0;
    for (int s=79+79; s>=79+3; s--){
        if (cnt == C) break;
        for (int i=79; i>=3; i--){
            int j = s-i;
            if (j > 79) break;
            cnt++;
            ans.push_back(vect(i, j));
            if (cnt == C) break;
        }
    }
    assert(ans.size() == V);
    for (auto v : ans){
        int x = v.x;
        int y = v.y;
        cout << x << ' ' << y << '\n';
    }
    assert(edges.size() == E);
    for (auto e: edges){
        cout << e.first+1 << ' ' << e.second+1 << '\n';
    }
}