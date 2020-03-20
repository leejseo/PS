#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int T;

lld gcd(lld a, lld b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    while (T--){
        lld a, b;
        cin >> a >> b;
        while (a != 0){
            lld g = gcd(a, b);
            a /= g; b /= g;
            lld t = (b-1)/a+1;
            // a/b - 1/t = (at - b)/bt
            a = a*t - b;
            b = b*t;
        }
        cout << (int)(sqrt(b)) << '\n';
    }
}
