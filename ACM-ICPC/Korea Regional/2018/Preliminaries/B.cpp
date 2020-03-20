#include <bits/stdc++.h>
using namespace std;

int a, b, n, w;

int x = -1, y = -1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b >> n >> w;
	for (int i=1; i<n; i++){
		int j = n - i;
		if (a*i+j*b == w){
			if (x != -1){
				cout << -1 << endl;
				return 0;
			}
			x = i, y = j;
		}
	}
	if (x == -1){
		cout << -1 << endl;
		return 0;
	}
	cout << x << ' ' << y << endl;
}
