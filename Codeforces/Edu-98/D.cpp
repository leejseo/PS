#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
const ll mod = 998'244'353;

ll D[200005];

ll osum, esum;

ll powmod(ll x, ll n){
    if (n == 0) return 1;
    x %= mod;
    ll res = 1;
    while (n){
        if (n & 1) res = (res * x) % mod;
        n >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    D[1] = 1;
    D[0] = 0;
    osum = 1, esum = 1;
    for (int i=2; i<=N+1; i++){
        D[i] = (D[i-1] + D[i-2]) % mod;
    }
    ll t = powmod(2, mod-2);
    ll ans = D[N];
    for (int i=1; i<=N; i++) ans = (ans * t) % mod;
    cout << ans << endl;
}