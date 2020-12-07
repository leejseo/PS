#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll x, y;
ll c[7], d[7];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        cin >> x >> y;
		for (int i=1; i<=6; i++) {
			cin >> c[i]; d[i] = c[i];
		}
		/*ll a1 = max(0LL, max(x, y));
		ll a4 = max(0LL, max(-x, -y));
		ll a3 = max(0LL, a1 - x);
		ll a6 = max(0LL, x - a4);
		ll a5 = max(0LL, a1 - y);
		ll a2 = max(0LL, y - a4);
		*/
		c[1] = min(c[1], d[6]+d[2]);
		c[3] = min(c[3], d[2]+d[4]);
		c[5] = min(c[5], d[4]+d[6]);
		c[2] = min(c[2], d[1]+d[3]);
		c[4] = min(c[4], d[3]+d[5]);
		c[6] = min(c[6], d[5]+d[1]);
		//ll c12 = min(2*c[1], c[6]+c[2]);
		//ll c32 = min(2*c[3], c[2]+c[4]);
		//ll c52 = min(2*c[5], c[4]+c[6]);
		//ll e = min(c[3], c[5]);
		//ll ans = a1 * c[1] + a3 * c[3] + a5 * c[5];
		//ans = min(ans, a2 * c[2] + a4 * c[4] + a6 * c[6]);
		//ans += (a1 % 2LL) * c[1];
		//ans += (a3 % 2LL) * c[3];
		//ans += (a5 % 2LL) * c[5];
		ll ans = 6E18;
		if (0 <= x && 0 <= y && x >= y){
			ans = min(ans, y * c[1] + (x-y) * c[6]);
		}
		if (0 <= x && 0 <= y && x <= y){
			ans = min(ans, x * c[1] + (y-x) * c[2]);
		}
		if (x <= 0 && 0 <= y){
			ans = min(ans, -x * c[3] + y * c[2]);
		}
		if (x <= 0 && y <= 0 && x <= y){
			ans = min(ans, -y*c[4] + (y-x) * c[3]);
		}
		if (x <= 0 && y <= 0 && y <= x){
			ans = min(ans, -x*c[4] + (x-y)*c[5]);
		}
		if (0 <= x && y <= 0){
			ans = min(ans, x * c[6] - y * c[5]);
		}
		cout << ans << '\n';
    }
}