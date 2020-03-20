#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int N, W, C, H, M;
vector<int> adj[1000][20];
bool A[1000]; // is human-controlled?
bool B[1000]; // is military base?
bool vis[1000][1000];

queue<pi> Q;

void init(){
    cin >> N >> W >> C >> H >> M;
    for (int i=0; i<H; i++){
        int u; cin >> u;
        A[u] = true;
    }
    for (int i=0; i<M; i++){
        int u; cin >> u;
        B[u] = true;
    }
    while (W--){
        int s, c, t;
        cin >> s >> c >> t;
        adj[s][--c].push_back(t);
    }
}

void solve(){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (A[i] && !A[j]){
                Q.push({i, j});
                vis[i][j] = true;
            }
        }
    }
    while (!Q.empty()){
        pi p = Q.front();
        int u = p.first, v = p.second;
        Q.pop();
        if (B[u] && B[v]){
            cout << "YES" << endl;
            return;
        }
        for (int c=0; c<C; c++){
            if (adj[u][c].size() == 0 || adj[v][c].size() == 0)
                continue;
            for (int i : adj[u][c]){
                for (int j : adj[v][c]){
                    if (!vis[i][j]){
                        vis[i][j] = true;
                        Q.push({i, j});
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    init();
    solve();
}
