By leejseo, contest: Codeforces Round #512 (Div. 2, based on Technocup 2019 Elimination Round 1), problem: (B) Vasya and Cornfield, Accepted, #
 #include <bits/stdc++.h>
using namespace std;

int n, d, m;

bool check(int x, int y){
	return (d <= x+y) && (x+y <= 2*n-d) && (-d <= x-y) && (x-y <= d);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> d;
	cin >> m;
	while (m--){
		int x, y;
		cin >> x >> y;
		if (check(x, y)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
