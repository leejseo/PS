#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;


ll a[11], b, ans;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i=0; i<11; i++){
        cin >> a[i];
        ll t; cin >> t;
        b += t;
    }
    sort(a, a+11);
    ll s = 0;
    for (int i=0; i<11; i++){
        s += a[i];
        ans += s;
    }
    cout << ans + 20LL*b << endl;
}