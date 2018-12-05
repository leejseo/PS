#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> A;
int S[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> K;
	A.resize(N);
	for (int i=0; i<N; i++) cin >> A[i];
	sort(A.begin(), A.end());
	A.resize(unique(A.begin(), A.end()) - A.begin());
	N = A.size();
	S[0] = A[0];
	for (int i=1; i<N; i++) S[i] = A[i] - A[i-1];
	for (int i=0; i<K; i++){
		if (i < N)
			cout << S[i] << '\n';
		else
			cout << 0 << '\n';
	}
}
