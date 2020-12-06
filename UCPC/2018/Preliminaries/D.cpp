#include <bits/stdc++.h>
using namespace std;
int N, a, b, rk[500001];
vector<int> adj[500001];
void input(){
	scanf("%d", &N);
	for (int i=1; i<N; i++){
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}
int dfs(int u, int n){
	int s = 0;
	rk[u] = n;
	bool b = 0;
	for (auto &v : adj[u]){
		if (rk[v] != -1) continue;
		s = s + dfs(v, n+1);
		s = s % 2;
		b = 1;
	}
	if (!b) return n;
	return s;
}

int main(){
	input();
	memset(rk, -1, sizeof(rk));
	if (dfs(1, 0)) printf("Yes\n");
	else printf("No\n");
}
