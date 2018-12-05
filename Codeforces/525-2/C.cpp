#include <bits/stdc++.h>
using namespace std;

int n;
int A[2001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> A[i];
	}
	cout << n+1 << '\n';
	cout << 1 << ' ' << n << ' ' << 199999-A[n-1] <<'\n';
	for (int i=0; i<n; i++){
		A[i] += 199999-A[n-1];
	}
	for (int i=n-2; i>=0; i--){
		cout << 1 << ' ' << i+1 << ' ';
		int to_add = 200000+i-(A[i]%100000);
		cout << to_add << '\n';
		for (int j=0; j<=i; j++){
			A[j] += to_add;
		}
	}
	cout << 2 << ' ' << n << ' ' << 100000;
}
