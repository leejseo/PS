#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

const lld INF = 1LL<<58;

lld A[500001], B[500001];
int n, m;

lld ans, num;

void solve(){
	int i = 0, j = 0;
	lld cur_ans = INF;
	lld count = 0LL;
	while (i < n && j < m){
		//cout << i << ' ' << j << '\n';
		lld tmp = abs(A[i] - B[j]);
		if (cur_ans == tmp) ++count;
		if (cur_ans > tmp){
			cur_ans = tmp;
			count = 1LL;
		}
		if (i == n-1){
			j++; continue;
		}
		if (j == m-1){
			i++; continue;
		}
		if (A[i] < B[j]){
			i++; continue;
		}
		if (A[i] == B[j] && A[i+1] < B[j+1]){
		 	i++; continue;
		}
		j++; continue;
	}
	ans = cur_ans;
	num = count;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	lld x, y;
	cin >> n >> m;
	cin >> x >> y;
	for (int i=0; i<n; i++) cin >> A[i];
	for (int i=0; i<m; i++) cin >> B[i];
	sort(A, A+n);
	sort(B, B+m);
	solve();
	ans += abs(x-y);
	cout << ans << ' ' << num << '\n';
}

