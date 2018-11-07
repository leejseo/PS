#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int maxint = 2e9;
int D[100005][4];
typedef pair<int, int> pii;
queue<pii> Q;
int sana(int x, int y){
    if (x == 0) return D[y][0];
    if (x == a) return D[y][1];
    if (y == 0) return D[x][2];
    if (y == b) return D[x][3];
    return maxint;
}
void change(int x, int y, int val){
    if (x == 0) {
        D[y][0] = val;
        return;
    }
    if (x == a){
        D[y][1] = val;
        return;
    }
    if (y == 0){
        D[x][2] = val;
        return;
    }
    D[x][3] = val;
    return;
}
void init(){
    for (int i=0; i<100005; i++){
        for (int j=0; j<4; j++){
            D[i][j] = maxint;
        }
    }
}
void BFS(){
    init();
    Q.push(make_pair(0, 0));
    D[0][0] = 0;
    while (!Q.empty()){
        pii xy = Q.front();
        Q.pop();
        int x = xy.first;
        int y = xy.second;
        int val = sana(x, y);
        if (sana(a, y) == maxint){
            Q.push(make_pair(a, y));
            change(a, y, val+1);
        }
        if (sana(0, y) == maxint){
            Q.push(make_pair(0, y));
            change(0, y, val+1);
        }
        if (sana(x, b) == maxint){
            Q.push(make_pair(x, b));
            change(x, b, val+1);
        }
        if (sana(x, 0) == maxint){
            Q.push(make_pair(x, 0));
            change(x, 0, val+1);
        }
        int u, v;
        v = min(a-x, y);
        u = min(x, b-y);
        if (sana(x+v, y-v) == maxint){
            Q.push(make_pair(x+v, y-v));
            change(x+v, y-v, val+1);
        }
        if (sana(x-u, y+u) == maxint){
            Q.push(make_pair(x-u, y+u));
            change(x-u, y+u, val+1);
        }
    }
}
int main(void){
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (0 < c && c < a && 0 < d && d < b){
        printf("-1");
        return 0;
    }
    BFS();
    int ans = sana(c, d);
    if (ans < maxint) printf("%d", ans);
    else printf("-1");
}
