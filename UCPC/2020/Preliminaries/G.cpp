#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;

int dist[200005];
const int INF = 1E9;

int A[200005];

vector<int> adj[200005];
int cnt[200005];

queue<int> Q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++){
        dist[i] = INF;
        int j;
        while (true){
            cin >> j;
            if (j == 0) break;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    cin >> M;
    for (int i=1; i<=M; i++) cin >> A[i];
    for (int i=1; i<=M; i++){
        dist[A[i]] = 0;
        Q.push(A[i]);
    }
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for (int v : adj[u]){
            if (dist[v] != INF) continue;
            cnt[v]++;
            if (cnt[v] + cnt[v] < adj[v].size()){
                continue;
            }
            dist[v] = dist[u] + 1;
            Q.push(v);
        }
    }
    for (int i=1; i<=N; i++){
        if (dist[i] != INF) cout << dist[i] << ' ';
        else cout << -1 << ' ';
    }
    cout << endl;
}
