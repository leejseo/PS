#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> A[100000];
int B[100000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i=0; i<n; i++){
		int s, r;
		cin >> s >> r;
		A[s-1].push_back(r);
	}
	for (int i=0; i<m; i++){
		sort(A[i].begin(), A[i].end());
		reverse(A[i].begin(), A[i].end());
	}
	for (int i=0; i<m; i++){
		int s = 0;
		for (int j=0; j<A[i].size(); j++){
			s += A[i][j];
			if (s > 0)
				B[j] += s;
			else
				break;
		}
	}
	int ans = 0;
	for (int i=0; i<n; i++)
		ans = max(ans, B[i]);
	cout << ans << endl;
}
