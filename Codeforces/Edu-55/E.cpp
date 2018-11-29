#include <bits/stdc++.h>
using namespace std;

int n, c;
int A[500001];
int Q[500001];
int C[500001];
int S[500001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> c;
	for (int i=0; i<n; i++){
		cin >> A[i];
		C[i+1] = C[i];
		if (A[i] == c) C[i+1]++;
	}
	int ans = C[n];
	for (int i=1; i<=n; i++){
		if (S[A[i-1]] == 0){
			ans = max(ans, C[i-1] + C[n] - C[i] + 1);
			S[A[i-1]]++;
			Q[A[i-1]] = max(Q[A[i-1]], C[i-1]);
			continue;
		}
		int val = S[A[i-1]] + 1 + C[n] - C[i];
		ans = max(ans, val+C[i-1]-S[A[i-1]]);
		ans = max(ans, val+Q[A[i-1]]);
		S[A[i-1]]++;
		Q[A[i-1]] = max(Q[A[i-1]], C[i-1]-S[A[i-1]]+1);
	}
	cout << ans << endl;
}
