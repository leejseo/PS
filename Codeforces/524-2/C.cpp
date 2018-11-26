#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

inline bool iswhite(int i, int j){
	return i%2 == j%2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		lld b=0, w=0;
		lld x1, y1, x2, y2, x3, y3, x4, y4;
		b += (n*1LL*m)/2LL;
		w += (n*1LL*m)/2LL;
		if (n % 2 == 1 && m % 2 == 1){
			w += 1;
		}
		cin >> x1 >> y1 >> x2 >> y2;
		lld numb = 0;
		numb += (x2-x1+1LL)*(y2-y1+1LL)/2LL;
		if (!((x2 - x1 + 1LL) % 2 == 0 || (y2 - y1 + 1LL) % 2 == 0))
			if (!iswhite(x1, y1))
				numb += 1;
		b -= numb;
		w += numb;
		cin >> x3 >> y3 >> x4 >> y4;
		lld numw = 0;
		numw += (x4-x3+1LL)*(y4-y3+1LL)/2LL;
		if (!((x4-x3+1LL)%2==0 || (y4-y3+1LL)%2==0))
			if (iswhite(x3, y3))
				numw += 1;
		b += numw;
		w -= numw;
		x1 = max(x1, x3), y1 = max(y1, y3);
		x2 = min(x2, x4), y2 = min(y2, y4);
		if (!(x2 < x1 || y2 < y1)){
			//cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
			numb = 0;
			numb += (x2-x1+1LL)*(y2-y1+1LL)/2LL;
			if (!((x2 - x1 + 1LL) % 2 == 0 || (y2 - y1 + 1LL) % 2 == 0)){
				if (!iswhite(x1, y1))
					numb += 1;
			}
			b += numb;
			w -= numb;
		}
		cout << w << ' ' << b << '\n';
	}
}
