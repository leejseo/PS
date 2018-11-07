#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int n, m;
lld x[300005];
lld y[300005];
lld prex[300005];
lld prey[300005];
int A[300005];
//int B[300005];
lld ans[300005];
//lld xy[300005];

bool comp(int i, int j){
	return x[i]-y[i] < x[j]-y[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> x[i] >> y[i];
		A[i] = i;
	}
	sort(A+1, A+n+1, comp);
	for (int j=1; j<=n; j++){
		int i = A[j];
		//B[i] = j;
		prex[j] = prex[j-1] + x[i];
		prey[j] = prey[j-1] + y[i];
		//xy[j] = x[i] - y[i];
	}	
	for (int i=1; i<=n; i++){
		ans[A[i]] += prex[i-1];
		ans[A[i]] += prey[n] - prey[i];
		ans[A[i]] += (i-1)*1LL*y[A[i]];
		ans[A[i]] += (n-i)*1LL*x[A[i]];
	}
	while (m--){
		int i, j;
		cin >> i >> j;
		//int u, v;
		//u = B[i], v = B[j];
		if (x[i] + y[j] < x[j] + y[i]){
			ans[i] -= x[i]+y[j];
			ans[j] -= x[i]+y[j];
		}
		else{
			ans[i] -= x[j]+y[i];
			ans[j] -= x[j]+y[i];
		}
	}
	for (int i=1; i<=n; i++) cout << ans[i] << ' ';
	cout << endl;
}
