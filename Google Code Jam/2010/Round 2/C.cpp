#include <bits/stdc++.h>
using namespace std;
 
struct Rect{
    int x1, y1, x2, y2;
    int mx, my, ms;
    void init(){ mx=x2, my=y2, ms=x1+y1; }
    bool meet(const Rect &R) const{
        int dx = min(x2, R.x2) - max(x1, R.x1);
        int dy = min(y2, R.y2) - max(y1, R.y1);
        return dx == -1 && dy == -1 ? (x1 < R.x1) ^ (y1 < R.y1) : dx >= -1 && dy >= -1;
    }
} R[1001];
 
struct DisjointSet{
    const static int MAXN = 1001;
    int par[MAXN], rk[MAXN];    
    DisjointSet(){}
    void init(){
        for (int i=0; i<MAXN; i++) par[i] = i, rk[i] = 1;
    }
    int find(int u){
        par[u] = (par[u] == u ? u : find(par[u]));
        return par[u];
    }
    void merge(int u, int v){
        u = find(u), v = find(v);
        if (rk[u] > rk[v]) swap(u, v); //rk[u] <= rk[v]
        par[u] = v;
        if (rk[u] == rk[v]) rk[v]++;
    }
} disj;
 
bool vis[1001];
int N;
 
int solve(){
    int ans = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<i; j++){
            if (R[i].meet(R[j])) disj.merge(i, j);
        }
    }
    for (int i=0; i<N; i++){
        int p = disj.find(i);
        if (vis[p]) continue;
        vis[p] = true;
        int mx = -1, my= -1, ms=20000000;
        for (int j=0; j<N; j++){
            if (disj.find(j) == p){
                ms = min(ms, R[j].ms);
                mx = max(mx, R[j].mx);
                my = max(my, R[j].my);
            }
        }
        ans = max(ans, mx+my-ms+1);
    }
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    for (int num=1; num<=T; num++){
        cin >> N;
        disj.init();
        for (int i=0; i<N; i++){
            cin >> R[i].x1 >> R[i].y1 >> R[i].x2 >> R[i].y2;
            R[i].init();
        }
        memset(vis, 0, sizeof(vis));
        cout << "Case #" << num << ": " << solve() << '\n';
    }
}
