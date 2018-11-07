#include <bits/stdc++.h>
using namespace std;

int N;
int A[1001];
int X[1000];

bool check(int fr, int len){
	for (int i=0; i<len; i++){
		if (i+fr >= N) return true;
		if (X[i] != X[i+fr]) return false;
	}
	if (fr + len == N) return true;
	return check(fr+len, len);
}

vector<int> ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i=1; i<=N; i++) cin >> A[i];
	for (int i=0; i<N; i++) X[i] = A[i+1] - A[i];
	for (int i=1; i<N; i++){
		if (check(0, i)) ans.push_back(i);
	}
	ans.push_back(N);
	cout << ans.size() << '\n';
	for (int i: ans) cout << i << ' ';
	cout << endl;
}
