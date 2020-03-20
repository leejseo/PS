#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

inline int bmod(int x, int y) { return (x+y)%y; }

int N, M;

vvi reverse_edges(vvi& adj){
	vvi adj_rev;
	adj_rev.resize(adj.size());
	for (int i=0; i<adj.size(); i++){
		int u = i;
		for (int j=0; j<adj[i].size();j++){
			int v = adj[i][j];
			adj_rev[v].push_back(u);
		}
	}
	return adj_rev;
}

void DFS(vvi &adj, int u, vi& visited, vi& node_stack){
	visited[u] = 1;
	for (int i=0; i<adj[u].size();i++){
		int v = adj[u][i];
		if (visited[v] == 0) DFS(adj, v, visited, node_stack);
	}
	node_stack.push_back(u);
}

vvi find_SCC(vvi& adj, vvi& adj_rev){
	vi vis_fw;
	vi nd_st;
	vis_fw.resize(adj.size(), 0);
	for (int i=0; i<adj.size(); i++){
		if (vis_fw[i] == 0) DFS(adj, i, vis_fw, nd_st);
	}
	vi vis_bw;
	vvi sccs;
	vis_bw.resize(adj_rev.size(), 0);
	for (int i=0; i<adj_rev.size(); i++){
		int u = nd_st.back();
		nd_st.pop_back();
		if (vis_bw[u]==0){
			vi scc;
			DFS(adj_rev, u, vis_bw, scc);
			sccs.push_back(scc);
			scc.clear();
		}
	}
	nd_st.clear();
	vis_fw.clear();
	vis_bw.clear();
	return sccs;
}

// Reducing 2-SAT into SCC

void build_graph(vector<pii> &P, vvi &adj){
	int k = P.size();
	int n = N;
	adj.resize(2*n);
	vi perm;
	perm.push_back(0);
	for (int i=1; i<n+1; i++) perm.push_back(n-1+i);
	perm.push_back(0);
	for (int i=n; i>0;   i--) perm.push_back(n-i);
	int m = perm.size();
	for (int j=0; j<k;   j++){
		int u = P[j].first, v = P[j].second;
		adj[perm[bmod(-u, m)]].push_back(perm[bmod(v, m)]);
		adj[perm[bmod(-v, m)]].push_back(perm[bmod(u, m)]);
	}
	perm.clear();
}

// 2-SAT Solver

vi solve(vector<pii> &P){
	vvi adj, adj_rev;
	int n = N;
	build_graph(P, adj);
	adj_rev = reverse_edges(adj);
	vvi sccs = find_SCC(adj, adj_rev);
	adj.clear();
	adj_rev.clear();
	vi sccID;
	sccID.resize(2*n+5);
	int m = sccID.size();
	for (int h=0; h<sccs.size(); h++){
		for (int i=0; i<sccs[h].size(); i++){
			int c = sccs[h][i];
			if (n <= c) c -= n-1;
			else c -= n;
			sccID[bmod(c, m)] = h;
		}
	}
	sccs.clear();
	vi ans;
	for (int i=1; i<n+1; i++) { if (sccID[i] == sccID[m-i]) return ans; }
	for (int i=1; i<n+1; i++) ans.push_back((sccID[i] > sccID[m-i]));
	sccID.clear();
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    vector<pii> P;
    while (M--){
        int i, j, k;
        char a, b, c;
        cin >> i >> a >> j >> b >> k >> c;
        if (a == 'B') i *= -1;
        if (b == 'B') j *= -1;
        if (c == 'B') k *= -1;
        P.push_back({i, j});
        P.push_back({j, k});
        P.push_back({k, i});
    }
    vi ans = solve(P);
    if (ans.empty()){
        cout << -1 << endl;
    }
    else{
        for (int i=0; i<N; i++){
            cout << (ans[i] ? 'R' : 'B');
        }
        cout << endl;
    }
}
