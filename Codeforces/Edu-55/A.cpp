#include <bits/stdc++.h>
using namespace std;

inline int ceil(int x, int y){
	return x % y == 0 ? x / y : x / y + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--){
		int n, x, y, d;
		cin >> n >> x >> y >> d;
		if (x % d == y % d){
			cout << abs(x-y)/d << '\n';
			continue;
		}	
		int v1 = -1;
		int v2 = -1;
		if ((y-1) % d == 0){
			v1 = ceil(x-1, d) + (y-1)/d;
		}
		if ((n-y) % d == 0){
			v2 = ceil(n-x, d) + (n-y)/d;
		}
		int ans = -1;
		if (v1 != -1){
			ans = (ans == -1 ? v1 : min(ans, v1));
		}
		if (v2 != -1){
			ans = (ans == -1 ? v2 : min(ans, v2));
		}
		cout << ans << '\n';
	}
}
