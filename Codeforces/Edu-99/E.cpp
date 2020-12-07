#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

ll x[4], y[4];

ll solve(int i, int j, int k, int l){
    ll ret = 0;
    // i l
    // j k
    ret += abs(x[i]-x[j]);
    ret += abs(y[j]-y[k]);
    ret += abs(x[k]-x[l]);
    ret += abs(y[i]-y[l]);
    ll a, b, c, d, minx, maxx, miny, maxy;
    {
        a = min(x[i], x[j]);
        b = max(x[i], x[j]);
        c = min(x[k], x[l]);
        d = max(x[k], x[l]);
        minx = min({
            abs(a-c), abs(a-d), abs(b-c), abs(b-d)
        });
        maxx = max({
            abs(a-c), abs(a-d), abs(b-c), abs(b-d)
        });
    }
    {
        a = min(y[i], y[l]);
        b = max(y[i], y[l]);
        c = min(y[k], y[j]);
        d = max(y[k], y[j]);
        miny = min({
            abs(a-c), abs(a-d), abs(b-c), abs(b-d)
        });
        maxy = max({
            abs(a-c), abs(a-d), abs(b-c), abs(b-d)
        });
    }
    if (maxy < minx || maxx < miny){
        ret += 2 * min({
            abs(maxx - miny),
            abs(maxx - maxy),
            abs(minx - miny),
            abs(minx - maxy)
        });
    }
    return ret;
}

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    for (int i=0; i<4; i++) v.push_back(i);
    while (T--){
        for (int i=0; i<4; i++) cin >> x[i] >> y[i];
        ll ans = 1E18;
        do{
            ans = min(ans, solve(v[0], v[1], v[2], v[3]));
        } while (next_permutation(v.begin(), v.end()));
        cout << ans << '\n';
    }
}