#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int T;

int CCW(int x1, int y1, int x2, int y2, int x3, int y3){
    int tmp = x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3;
    if (tmp == 0) return 0;
    return tmp / abs(tmp);
}


int intersect(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy){
    pair<int, int> a = {ax, ay}, b = {bx, by}, c = {cx, cy}, d = {dx, dy};
    if (a > b) swap(a, b); // a <= b
    if (c > d) swap(c, d); // c <= d
    if (CCW(ax, ay, bx, by, cx, cy) == 0 && CCW(ax, ay, bx, by, dx, dy) == 0){
        if (a == d || b == c) return 1;
        if (b < c || a > d) return 0;
        return 10;
    }
    if (CCW(ax, ay, bx, by, cx, cy) == CCW(ax, ay, bx, by, dx, dy)) return 0;
    if (CCW(cx, cy, dx, dy, ax, ay) == CCW(cx, cy, dx, dy, bx, by)) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    while (T--){
        int xmin, ymin, xmax, ymax;
        int x1, y1, x2, y2;
        cin >> xmin >> ymin >> xmax >> ymax;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2 || x1 == x2 && y1 > y2){
            swap(x1, x2);
            swap(y1, y2);
        }
        int ans = 0;
        ans += intersect(x1, y1, x2, y2, xmin, ymin, xmax, ymin);
        ans += intersect(x1, y1, x2, y2, xmax, ymin, xmax, ymax);
        ans += intersect(x1, y1, x2, y2, xmax, ymax, xmin, ymax);
        ans += intersect(x1, y1, x2, y2, xmin, ymax, xmin, ymin);
        if (intersect(x1, y1, x2, y2, xmin, ymin, xmin, ymin)) ans--;
        if (intersect(x1, y1, x2, y2, xmin, ymax, xmin, ymax)) ans--;
        if (intersect(x1, y1, x2, y2, xmax, ymax, xmax, ymax)) ans--;
        if (intersect(x1, y1, x2, y2, xmax, ymin, xmax, ymin)) ans--;
        if (ans > 2) cout << 4 << '\n';
        else cout << ans << '\n';
    }
}
