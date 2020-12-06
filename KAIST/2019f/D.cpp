#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;

const int INF = 1E9;

int N, M;
vector<int> adj[505];
int dist[505];

queue<int> Q;

void init(){
    fill(dist, dist+N+1, (int)1E9);
    while (!Q.empty()) Q.pop();
}

bool trial(int s){
    init();
    dist[s] = 0;
    Q.push(s);
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for (int v : adj[u]){
            if (dist[v] != INF){
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    for (int u=1; u<=N; u++){
        for (int v : adj[u]){
            if (dist[u] > dist[v]) return false;
        }
    }
    return true;
}

vector<int> ans;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    while (M--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i=1; i<=N; i++) if (trial(i)) ans.push_back(i);
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i : ans) cout << i << ' ';
}