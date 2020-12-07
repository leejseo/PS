#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        ll l, r; cin >> l >> r;
        if (r >= 2 * l) cout << "NO" << '\n';
        else cout << "YES\n";
    }
}