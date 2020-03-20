#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9;

struct Dinic{
  // dinic code: from ntopia님의 팀노트
	struct Edge{
		int next, inv, res;
	};

	int n;
	vector<vector<Edge>> graph;
	vector<int> q, l, start;

	void init(int m){
		n = m;
		graph.resize(n);
		for (int i=0; i<n; i++) graph[i].clear();
	}

	void add_edge(int s, int e, int cap, int caprev=0){
		Edge forward{e, graph[e].size(), cap};
		Edge reverse{s, graph[s].size(), caprev};
		graph[s].push_back(forward);
		graph[e].push_back(reverse);
	}

	bool assign_level(int source, int sink){
		int t = 0;
		memset(&l[0], 0, sizeof(l[0])*l.size());
		l[source] = 1;
		q[t++] = source;
		for (int h=0; h<t && !l[sink]; h++){
			int cur = q[h];
			for (const auto &e : graph[cur]){
				if (l[e.next] || e.res == 0) continue;
				l[e.next] = l[cur]+1;
				q[t++] = e.next;
			}
		}
		return l[sink] != 0;
	}

	int block_flow(int cur, int sink, int current){
		if (cur == sink) return current;
		for (int &i=start[cur]; i < graph[cur].size(); i++){
			auto &e = graph[cur][i];
			if (e.res == 0 || l[e.next] != l[cur] + 1) continue;
			if (int res = block_flow(e.next, sink, min(e.res, current))){
				e.res -= res;
				graph[e.next][e.inv].res += res;
				return res;
			}
		}
		return 0;
	}
	int solve(int source, int sink){
		q.resize(n);
		l.resize(n);
		start.resize(n);
		int ans = 0;
		while (assign_level(source, sink)){
			memset(&start[0], 0, sizeof(start[0])*n);
			while (int flow = block_flow(source, sink, INF)){
				ans += flow;
			}
		}
		return ans;
	}
} flow;

int N, M;
vector<int> adj[105];

void proc(){
	flow.init(2*N+5);
	for (int u=1; u<=N; u++){
		flow.add_edge(u, N+u, 1);
		for (int v : adj[u]){
			flow.add_edge(N+v, u, INF);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	while (M--){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			if (i == j) continue;
			proc();
			if (flow.solve(j+N, i) < N/2){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << 1 << endl;
}
