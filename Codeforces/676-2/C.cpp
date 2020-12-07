#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
string S;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> S;
	N = S.size();
	cout << 3 << '\n';
	cout << 'R' << ' ' << 2 << '\n';
	cout << 'L' << ' ' << N << '\n';
	cout << 'L' << ' ' << N-1 << '\n';
}