/*************************************************************************
 ** Source Code for Network Flow Credits to TEAM "Please Open Testdata" **
 ************************ Modified by Jongseo Lee ************************
 *************************************************************************/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;

typedef struct{
 
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
		Edge forward = {e, graph[e].size(), cap};
		Edge reverse{s, graph[s].size(), caprev};
		graph[s].push_back(forward);
		graph[e].push_back(reverse);
	}
 
	bool assign_level(int source, int sink){
		int t=0;
		memset(&l[0], 0, sizeof(l[0]) * l.size());
		l[source] = 1;
		q[t++] = source;
		for (int h=0; h < t && !l[sink]; h++){
			int cur = q[h];
			for (const auto &e: graph[cur]){
				if (l[e.next] || e.res == 0) continue;
				l[e.next] = l[cur] + 1;
				q[t++] = e.next;
			}
		}
		return l[sink] != 0;
	}
 
	int block_flow(int cur, int sink, int current){
		if (cur == sink) return current;
		for (int &i=start[cur]; i<graph[cur].size(); i++){
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
} Dinic;

Dinic flow;

struct Edg{
	int u, v, w;
	Edg(int u_=0, int v_=0, int w_=0){ u=u_;v=v_;w=w_; }
	bool operator < (const Edg &other) const{
		return w < other.w;
	}
} E[501];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i=0; i<m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		E[i] = Edg(u, v, w);
	}
	int ans = 0;
	sort(E, E+m);
	for (int i=0; i<m; i++){
		int w = E[i].w;
		flow.init(n+1);
		for (int j=0; j<m; j++){
			if (E[j].w >= w) break;
			flow.add_edge(E[j].u, E[j].v, 1);
			flow.add_edge(E[j].v, E[j].u, 1);
		}
		ans += flow.solve(E[i].u, E[i].v);
	}
	cout << ans << '\n';
}
