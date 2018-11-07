#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int N, M, S, E, T, M_;
int C[3001][6001], F[3001];
int D[3001][6001];
int A[3001][6001];
int B[3001][6001];

typedef pair<int, int> pii;

deque<pii> que[3001];

void init(){
	cin >> N >> M_ >> S >> E >> T;
	M = M_+S-1;
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M_; j++) cin >> C[i][j];
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){ 
			D[i][j] = INF;
			A[i][j] = A[i][j-1] + C[i][j];
		}
	}
	for (int i=1; i<=N; i++) cin >> F[i];
}

void solve(){
	for (int j=1; j<=M; j++){
		pii min3[3] = {pii(INF, -1), pii(INF, -1), pii(INF, -1)};
		//update D
		for (int i=1; i<=N; i++){
			while (que[i].size() && que[i].front().second < j-E) 
				que[i].pop_front();
			if (j - S >= S){
				pii tmp = pii(B[i][j-S], j-S);
				while (que[i].size() && que[i].back() >= tmp)
					que[i].pop_back();
				que[i].push_back(tmp);
			}
			if (que[i].size()) D[i][j] = min(D[i][j], que[i].front().first + A[i][j] + T);
			if (j <= E) D[i][j] = min(D[i][j], A[i][j]);
			pii tmp = pii(D[i][j], i);
			if (min3[0] >= tmp){
				min3[2] = min3[1], min3[1] = min3[0], min3[0] = tmp;
			}
			else if (min3[1] >= tmp){
				min3[2] = min3[1], min3[1] = tmp;
			}
			else if (min3[2] >= tmp){
				min3[2] = tmp;
			}
		}
		//update E
		for (int i=1; i<=N; i++){
			for (int k=0; k<3; k++){
				if (min3[k].second != i && min3[k].second != F[i]){
					B[i][j] = min3[k].first - A[i][j];
					break;
				}
			}
		}
	}	
	int ans = INF;
	for (int i=1; i<=N; i++)
		for (int j=M_; j<=M; j++)
			ans = min(ans, D[i][j]);
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	init();	
	solve();
}
