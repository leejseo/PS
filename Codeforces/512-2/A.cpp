#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	int c, s = 0;
	for (int i=0; i<N; i++){
		cin >> c;
		s += c;
	}
	if (s == 0) cout << "EASY" << endl;
	else cout << "HARD" << endl;
}
