#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        int ans = x+x;
        y -= x;
        if (y > 0){
            ans += 2 * (y-1) + 1;
        }
        cout << ans << '\n';
    }
}