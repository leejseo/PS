#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> S;
vector<int> A[200005];

int N, M;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i=1; i<=M; i++) {
		S.clear();
		int n; cin >> n; S.resize(n);
		for (int i=0; i<n; i++) cin >> S[i];
		for (auto x : S) A[x].push_back(S.size());
	}
	double ans = 0;
	for (int i=1; i<=N; i++) {
		double cur = 1;
		for (auto x : A[i]) cur = min(cur, (x-1.0)/x);
		ans = max(ans, cur);
	}
	cout << ans << endl;
}
