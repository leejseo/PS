#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
int D1[5001][5001], D2[5001][5001];
bool B[5001];
int U[5001], V[5001];
vector<int> adj[5001];
int siz[5001];
int ans;

void dfs(int u, int p){
	int cur = 0;
	int X[5001], Y[5001];
	for (int v : adj[u]){
		if (v == p) continue;
		dfs(v, u);
		memset(X, 0x3f, sizeof(X));
		memset(Y, 0, sizeof(Y));
		for (int i=0; i<=cur; i++){
			for (int j=0; j<=siz[v]; j++){
				X[i+j] = min(X[i+j], D1[u][i]+D1[v][j]);
				Y[i+j] = max(Y[i+j], D2[u][i]+D2[v][j]);
			}
		}
		cur += siz[v];
		for (int i=0; i<=cur; i++) D1[u][i] = X[i], D2[u][i] = Y[i];
	}
	siz[u] = cur;
	for (int i=0; i<=siz[u]; i++) D1[u][i]++, D2[u][i]++;
	if (B[u]){ 
		for (int i=++siz[u]; i; i--){
			D1[u][i] = D1[u][i-1];
			D2[u][i] = D2[u][i-1];
		}
		D1[u][0] = D2[u][0] = 0;
	}
	else D1[u][0] = 0;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
	while (M--){
		int u; cin >> u;
		B[u] = 1;
	}
	for (int i=1; i<N; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(D1, 0x3f, sizeof(D1));
	memset(U, 0x3f, sizeof(U));
	for (int i=1; i<=N; i++) D1[i][0] = 0;
	dfs(1, 0);
	for (int i=1; i<=N; i++)
		for (int j=0; j<=siz[i]; j++)
			U[j] = min(U[j], D1[i][j]), V[j] = max(V[j], D2[i][j]);
	cin >> Q;
	while (Q--){
		int i, j;
		cin >> i >> j;
		if (U[j] <= i && i <= V[j]) ++ans;
	}
	cout << ans << endl;
}