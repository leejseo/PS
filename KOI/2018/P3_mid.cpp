#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pi;

int N, M, H;

vector<pi> adj[1500005];
int A[1500005];

priority_queue<pi, vector<pi>, greater<pi>> pq;

inline void to_xy(int n, int &x, int &y){
	x = n / 1005;
	y = n % 1005;
}

inline int do_hash(int x, int y){
	if (x == 0 || y == 0) return 0;
	return x * 1005 + y;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> H;
	fill(A, A+do_hash(N, M)+1, H);
	for (int i=0; i<=N; i++){
		int ux = i, vx = (i+1)%(N+1);
		for (int j=1; j<=M; j++){
			int h;
			cin >> h;
			if (h == -1) continue;
			int uy = j, vy = j;
			int u = do_hash(ux, uy);
			int v = do_hash(vx, vy);
			adj[u].push_back({v, h});
			adj[v].push_back({u, h});
		}
	}
	for (int i=1; i<=N; i++){
		int ux = i, vx = i;
		for (int j=0; j<=M; j++){
			int uy = j, vy = (j+1)%(M+1);
			int u = do_hash(ux, uy);
			int v = do_hash(vx, vy);
			int h;
			cin >> h;
			if (h == -1) continue;
			adj[u].push_back({v, h});
			adj[v].push_back({u, h});
		}
	}
	A[0] = 0;
	pq.push({0, 0});
	while (!pq.empty()){
		pi p = pq.top();
		pq.pop();
		int a = p.first, u = p.second;
		if (A[u] != a) continue;
		for (pi q : adj[u]){
			int v = q.first;
			int h = q.second;
			int a_v = max(h, A[u]);
			if (a_v < A[v]){
				A[v] = a_v;
				pq.push({a_v, v});
			}
		}
	}
	ll ans = 0;
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
			ans += A[do_hash(i, j)];
	cout << ans << endl;
}
