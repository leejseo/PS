#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

lld GCD(lld u, lld v) {
	while (v != 0) {
		lld r = u % v;
		u = v;
		v = r;
	}
	return u;
}

lld n, m, k, nn, mm, kk;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> k;
	nn = n, mm = m;
	lld g1 = GCD(n, k);
	n /= g1;
	k /= g1;
	lld g2 = GCD(m, k);
	m /= g2;
	k /= g2;
	if (k > 2){
		cout << "NO" << '\n';
		return 0;
	}
	if (k == 1){
		if (g1 > 1) n *= 2;
		else m*= 2;
		cout << "YES" << '\n';
		cout << "0 0" << '\n';
		cout << n << " 0" << '\n';
		cout << "0 " << m << '\n';
		return 0;
	}
	cout << "YES" << '\n';
	cout << "0 0" << '\n';
	cout << n << " 0" << '\n';
	cout << "0 " << m << '\n';
	return 0;
}
