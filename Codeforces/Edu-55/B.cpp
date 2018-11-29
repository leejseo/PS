#include <bits/stdc++.h>
using namespace std;

int N;
char s[100001];
int A[100001], B[100002];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	cin >> s;
	int numG = 0;
	for (int i=0; i<N; i++){
		if (s[i] == 'G')
			A[i+1] = A[i] + 1, numG = numG + 1;
		else
			A[i+1] = 0;
	}
	for (int i=N-1; i>=0; i--){
		if (s[i] == 'G')
			B[i+1] = B[i+2] + 1;
		else
			B[i+1] = 0;
	}
	int ans = 0;
	for (int i=1; i<=N; i++){
		ans = max(ans, A[i]);
	}
	for (int i=2; i<N; i++){
		if (A[i-1] + B[i+1] < numG){
			ans = max(ans, A[i-1]+B[i+1]+1);
		}
		if (A[i-1] + B[i+1] == numG)
			ans = max(ans, numG);
	}
	cout << ans << endl;
}
