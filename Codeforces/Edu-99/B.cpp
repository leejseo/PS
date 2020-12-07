#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        int x; cin >> x;
        int ans = 0, cur = 0;
        while (cur < x){
            cur += (++ans);
        }
        if (cur == x+1) ans++;
        cout << ans << '\n';
    }
}