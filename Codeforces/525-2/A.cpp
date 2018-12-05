#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int x;
	cin >> x;
	for (int a=1; a<=x;a++){
		for (int b=1; b<=x; b++){
			if (a*b > x && a < x * b && a % b == 0){
				cout << a << ' ' << b << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}
