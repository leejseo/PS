#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1'000'000'007;

ll D[501][50001];

void fill_table() {
    D[1][0] = 1, D[1][1] = 1;
    for (int r=2; r<=500; r++) {
        for (int i=0; i<=50000; i++) {
            int j = r*(r+1)/2 - i;
            if (i >= r) D[r][i] += D[r-1][i-r];
            if (j >= r) D[r][i] += D[r-1][i];
            D[r][i] %= mod;
        }
    }
    for (int r=1; r<=500; r++) {
        for (int i=1; i<=50000; i++) {
            D[r][i] += D[r][i-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill_table();
    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;
        ll ans = 0;
        for (ll r=1; r*(r+1) <= 2*(a+b); r++) {
            ll cur = D[r][a];
            int mina = r*(r+1)/2 - b;
            if (mina > 0) {
                cur -= D[r][mina-1];
            }
            cur += mod;
            cur %= mod;
            ans = (ans + cur) % mod;
        }
        cout << ans << '\n';
    }
}
