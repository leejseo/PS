#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

inline double go(double x, double y){
    return min(360-abs(x-y), abs(x-y));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    cout << setprecision(15) << fixed;
    while (T--){
        int h, m, s;
        cin >> h >> m >> s;
        double a, b, c;
        c = 6 * s; // 60 * 6 = 360
        b = 6 * m + 0.1 * s;
        a = 30 * h + m / 2.0 + s / 120.0;
        cout << min({go(a, b), go(b, c), go(c, a)}) << '\n';
    }
}