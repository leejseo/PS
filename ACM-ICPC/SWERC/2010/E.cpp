#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

inline int abs(int n) { return max(n, -n); }
inline int bmod(int x, int y) { return (x+y)%y; }

// Kosaraju's Finding SCC Algorithm
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
	int n = 2*N;
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

bool solve(vector<pii> &P){
	vvi adj, adj_rev;
	int n = 2*N;
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
	sccID.clear();
	for (int i=1; i<n+1; i++) { if (sccID[i] == sccID[m-i]) return false; }
	return true;
}

char C[10005];

char X[] = {
    'A', 'G', 'T', 'C'
};

inline char nxt(char c){
    for (int i=0; i<4; i++) if (X[i] == c) return X[(i+1)%4];
}

inline char prv(char c){
    for (int i=0; i<4; i++) if (X[i] == c) return X[(i+3)%4];
}

inline int _nxt(int n){
    return n;
}

inline int _prv(int n){
    return n+N;
}

vector<pii> P;

int I[6005];

int main(){
    while (true){
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;
        scanf("%s", C+1);
        for (int i=1; i<N; i++){
            P.push_back({-_prv(i), -_prv(i+1)});
            P.push_back({-_prv(i), -_nxt(i+1)});
            P.push_back({-_nxt(i), -_nxt(i+1)});
            P.push_back({-_nxt(i), -_prv(i+1)});
        }
        for (int i=1; i<=N; i++){
            P.push_back({-_prv(i), -_nxt(i)});
        }
        while (M--){
            int K;
            scanf("%d:", &K);
            for (int i=1; i<=K; i++) scanf("%d", &I[i]);
            for (int i=1; i<=K; i++) I[i]++;
            for (int i=1; i<=K; i++){
                if (i+i > K) break;
                int x = I[i], y = I[K-i+1];
                if (C[x] == C[y]){
                    P.push_back({_nxt(x), -_nxt(y)});
                    P.push_back({-_nxt(x), _nxt(y)});
                    P.push_back({_prv(x), -_prv(y)});
                    P.push_back({-_prv(x), _prv(y)});
                    continue;
                }
                if (nxt(C[x]) == C[y]){
                    P.push_back({_nxt(x), _prv(y)});
                    P.push_back({-_nxt(x), -_prv(y)});
					P.push_back({_nxt(x), -_prv(x)});
					P.push_back({_prv(y), -_nxt(y)});
                    continue;
                }
                if (nxt(C[y]) == C[x]){
                    P.push_back({_nxt(y), _prv(x)});
                    P.push_back({-_nxt(y), -_prv(x)});
					P.push_back({_nxt(y), -_prv(y)});
					P.push_back({_prv(x), -_nxt(x)});
                    continue;
                }
                if (nxt(C[y]) == prv(C[x])){
                    P.push_back({_nxt(x), _prv(x)});
                    P.push_back({_nxt(y), _prv(y)});
                    P.push_back({-_nxt(x), _prv(y)});
                    P.push_back({-_prv(x), _nxt(y)});
                    continue;
                }
            }
        }
        if (!solve(P)){
            printf("NO\n");
        }
        else{
            printf("YES\n");
		}
        P.clear();
    }
}
