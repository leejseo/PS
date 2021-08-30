#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll H[300005];
const ll mod = 1'000'000'007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> H[i];
    H[0] = H[N+1] = 2E9;
    ll ans = 1;
    for (int i=1; i<=N; i++) {
        ans = (ans * (min({H[i-1], H[i], H[i+1]}))) % mod;
    }
    cout << ans << endl;
}
