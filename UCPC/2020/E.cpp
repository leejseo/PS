#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long INF = 1E12;

struct MaxFlowDinic {
    typedef long long flow_t;
    struct Edge {
        int next;
        size_t inv; /* inverse edge index */
        flow_t res; /* residual */
    };
    int n;
    vector<vector<Edge>> graph;
    vector<int> q, l, start;

    void init(int _n) {
        n = _n;
        graph.resize(n);
        for (int i = 0; i < n; i++) graph[i].clear();
    }
    void add_edge(int s, int e, flow_t cap, flow_t caprev = 0) {
        Edge forward{ e, graph[e].size(), cap };
        Edge reverse{ s, graph[s].size(), caprev };
        graph[s].push_back(forward);
        graph[e].push_back(reverse);
    }
    bool assign_level(int source, int sink) {
        int t = 0;
        memset(&l[0], 0, sizeof(l[0]) * l.size());
        l[source] = 1;
        q[t++] = source;
        for (int h = 0; h < t && !l[sink]; h++) {
            int cur = q[h];
            for (const auto& e : graph[cur]) {
                if (l[e.next] || e.res == 0) continue;
                l[e.next] = l[cur] + 1;
                q[t++] = e.next;
            }
        }
        return l[sink] != 0;
    }
    flow_t block_flow(int cur, int sink, flow_t current) {
        if (cur == sink) return current;
        for (int& i = start[cur]; i < graph[cur].size(); i++) {
            auto& e = graph[cur][i];
            if (e.res == 0 || l[e.next] != l[cur] + 1) continue;
            if (flow_t res = block_flow(e.next, sink, min(e.res, current))) {
                e.res -= res;
                graph[e.next][e.inv].res += res;
                return res;
            }
        }
        return 0;
    }
    flow_t solve(int source, int sink) {
        q.resize(n);
        l.resize(n);
        start.resize(n);
        flow_t ans = 0;
        while (assign_level(source, sink)) {
            memset(&start[0], 0, sizeof(start[0]) * n);
            while (flow_t flow = block_flow(source, sink, numeric_limits<flow_t>::max()))
                ans += flow;
        }
        return ans;
    }
} dinic;

int N, M, K;

int S, E;
int C[205];

vector<int> adj[100005];
bool vis[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    cin >> S >> E;
    dinic.init(10*N+5);
    int src = 10*N+3, snk = 10*N+4;
    int X = 2*N;
    for (int i=1; i<=N; i++){
        cin >> C[i];
    }
    for (int k=0; k<K; k++){
        int base = k * X;
        for (int i=1; i<=N; i++){
            dinic.add_edge(base+i, base+N+i, C[i]);
        }
        if (k != K-1){
            for (int i=1; i<=N; i++)
                dinic.add_edge(base+i, base+X+N+i, INF);
        }
    }
    for (int k=0; k<K; k++){
        dinic.add_edge(src, k*X+S, INF);
        dinic.add_edge(k*X+N+E, snk, INF);
    }
    while (M--){
        int u, v; cin >> u >> v;
        for (int k=0; k<K; k++){
            int base = k * X;
            dinic.add_edge(base+N+u, base+v, INF);
        }
    }
    ll flow = dinic.solve(src, snk);
    if (flow > (ll)1E10){
        cout << -1 << endl;
        return 0;
    }
    if (flow == 0){
        cout << 0 << endl;
        return 0;
    }
    for (int i=0; i<dinic.n; i++){
        for (auto e : dinic.graph[i]){
            int j = e.next;
            if (e.res != 0){
                adj[i].push_back(j);
            }
        }
    }
    {
        queue<int> Q;
        Q.push(src);
        vis[src] = true;
        while (!Q.empty()){
            int u = Q.front();
            Q.pop();
            for (int v : adj[u]){
                if (!vis[v]){
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
    }
    set<int> ans;
    for (int k=0; k<K; k++){
        int base = k*X;
        for (int i=1; i<=N; i++){
            if (vis[base+i] != vis[base+N+i]){
                ans.insert(i);
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';
    cout << endl;
}