#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1E16;

int N, M, A, B, K;

ll dist[105005];
int S[2005], E[2005];
priority_queue<pair<ll, int>> pq;

vector<pair<int, ll>> adj[105005];

void dijkstra(int start){
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()){
        auto p = pq.top(); pq.pop();
        ll d; int u; tie(d, u) = p; d = -d;
        if (d != dist[u]) continue;
        for (auto p : adj[u]){
            ll w; int v; tie(v, w) = p;
            ll dv = dist[u] + w;
            if (dv < dist[v]){
                dist[v] = dv;
                pq.push({-dv, v});
            }
        }
    }
}

void add_edge(int s, int e, ll x){
    adj[s].push_back({e, x});
    adj[e].push_back({s, x});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> A >> B;
    --A; --B;
    fill(dist, dist+105000, INF);
    for (int i=0; i<M; i++){
        cin >> S[i] >> E[i]; ll x; cin >> x;
        --S[i]; --E[i];
        add_edge(S[i], E[i], x);
    }
    cin >> K;
    for (int l=1; l<=K; l++){
        for (int i=0; i<N; i++){
            adj[(l-1)*N+i].push_back({l*N+i, 0});
        }
    }
    for (int l=1; l<=K; l++){
        for (int i=0; i<M; i++){
            ll x; cin >> x;
            add_edge(l*N+S[i], l*N+E[i], x);
        }
    }
    int st = A, ed = K*N+B;
    dijkstra(st);
    cout << dist[ed] << endl;
}
