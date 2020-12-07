#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1'000'000'007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll suf = 0, ans = 0;
    int N; cin >> N;
    for (int i=1; i<N; i++){
        ll a; cin >> a;
        suf = (++suf * a) % mod;
        ans = (ans + suf) % mod;
    }    
    cout << ans << endl;
}
