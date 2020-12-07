#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
		ll a, b; cin >> a >> b;
		ll res = 0;
		for (int i=0; i<32; i++){
			ll cur = 1LL << i;
			//cout << cur << ' ' << (a & cur) << ' ' << (b & cur) << '\n';
			if ((a & cur) != (b & cur)) res += cur;
		}
		cout << res << '\n';
    }
}