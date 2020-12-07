#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        ll x, y; cin >> x >> y;
        cout << x-1 << ' ' << y << '\n';
    }
}