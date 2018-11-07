#include <stdio.h>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
int N, K;
int par[4000005];
int D[2001][2001];
bool vis[2001][2001];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int C; // number of civilizations
int maxint = 2e9;
typedef pair<int, int> pii;
inline int con(int u, int v) {return (u-1)*N + v;}
inline bool valid (int u, int v) {return ((1<= u  && u <= N) && (1 <= v && v <= N));}
queue<pii> Q;

int find(int u){
	if (u == par[u]) return u;
	par[u] = find(par[u]);
	return par[u];
}

void merge(int u, int v){
	u = find(u);
	v = find(v);
	if (u != v) C -= 1;
	par[v] = u;
}

void init(){
	scanf("%d%d", &N, &K);
	for (int i=0; i<4000005; i++){
		par[i] = i;
	}
	for (int i=1; i<2001; i++){
		for (int j=1; j<2001; j++){
			D[i][j] = maxint;
		}
	}
	int u, v;
	for (int i=1; i<=K; i++){
		scanf("%d%d", &u, &v);
		D[u][v] = 0;
		Q.push(make_pair(u, v));
		vis[u][v] = 1;
	}
}

int BFS(){
	int ans = 0;
	while(1){
		while(!Q.empty()){
			pii rc = Q.front();
			int r = rc.first, c = rc.second;
			Q.pop();
			if (D[r][c] != ans){
				Q.push(make_pair(r, c));
				break;
			}
			vis[r][c] = 1;
			C++;
			for (int d =0; d<4; d++){
				int nr = r + dr[d];
				int nc = c + dc[d];
				if (!valid(nr, nc)) continue;
				if (vis[nr][nc]) merge(con(nr, nc), con(r, c));
				else if (D[nr][nc] == maxint){
					D[nr][nc] = D[r][c] + 1;
					Q.push(make_pair(nr, nc));
				}
			}
		}
		if (C == 1) break;
		ans++;
	}
	return ans;
}

int main(void){
	init();
	printf("%d", BFS());
}
