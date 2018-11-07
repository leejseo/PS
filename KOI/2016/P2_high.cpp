#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define maxint 9E18
#define all(v) v.begin(), v.end()
#define MAXV 2500
#define MAXE 4000

int V, E;
int oil[MAXV];


struct Edge{
    int to;
    long long weight;
    Edge (int t_, long long w_) {to = t_; weight = w_;}
};


vector<Edge> cost_graph[MAXV];

struct Node{
    int u;
    long long dist;
    Node (int u_, long long d_) {u = u_; dist = d_;}
    bool operator < (const Node &a) const {return dist > a.dist;}
};

vector<Edge> adj[MAXV];

vector<long long> dijkstra(int start, vector<Edge> *adj_list){
    priority_queue<Node> Q;
    vector <long long> dist(V, maxint);
    dist[start] = 0;
    Q.push(Node(start, 0));
    while (!Q.empty()){
        int u = Q.top().u;
        long long dist_u = Q.top().dist;
        Q.pop();
        if (dist[u] < dist_u) {
            continue;
        }
        for (int i=0; i<adj_list[u].size(); i++){
            int v = adj_list[u][i].to;
            long long dist_v = dist_u + adj_list[u][i].weight;
            if (dist_v < dist[v]){
                dist[v] = dist_v;
                Q.push(Node(v, dist_v));
            }
        }
    }
    return dist;
}

long long solve(){
    for (int i=0; i<V; i++){
        vector<long long> dist = dijkstra(i, adj);
        for (int j=0; j<V; j++){
            if (j == i || dist[j] == maxint){
                continue;
            }
            long long cost = dist[j] * oil[i];
            cost_graph[i].push_back(Edge(j, cost));
        }
    }
    return dijkstra(0, cost_graph)[V-1];
}

int main(){
    scanf("%d %d", &V, &E);
    for (int i=0; i<V; i++){
        scanf("%d", &oil[i]);
    }
    for (int i=0; i<E; i++){
        int fr, to, weight;

        scanf("%d %d %d", &fr, &to, &weight);
        fr--; to--;
        adj[fr].push_back(Edge(to, weight));
        adj[to].push_back(Edge(fr, weight));
    }
    long long r = solve();
    printf("%lld\n", r);
    return 0;
}

