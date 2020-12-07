#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int N;
char S[205][205];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        cin >> N;
		for (int i=0; i<N; i++) cin >> S[i];
		vector<pair<int, int>> b0, b1, c0, c1;
		if (S[0][1] == '0') b0.push_back({0, 1});
		else b1.push_back({0, 1});
		if (S[1][0] == '0') b0.push_back({1, 0});
		else b1.push_back({1, 0});
		for (int i=0; i<=2; i++){
			if (S[i][2-i] == '0') c0.push_back({i, 2-i});
			else c1.push_back({i, 2-i});
		}
		if (c0.empty()){
			cout << b1.size() << '\n';
			for (auto p : b1){
				cout << p.first + 1 << ' ' << p.second + 1 << '\n';
			}
			continue;
		}
		if (c1.empty()){
			cout << b0.size() << '\n';
			for (auto p : b0){
				cout << p.first + 1 << ' ' << p.second + 1 << '\n';
			}
			continue;
		}
		if (b0.empty()){
			cout << c1.size() << '\n';
			for (auto p : c1){
				cout << p.first + 1 << ' ' << p.second + 1 << '\n';
			}
			continue;
		}
		if (b1.empty()){
			cout << c0.size() << '\n';
			for (auto p : c0){
				cout << p.first + 1 << ' ' << p.second + 1 << '\n';
			}
			continue;
		}
		if (c0.size() < c1.size()){
			swap(c0, c1);
			swap(b0, b1);
		}
		cout << c1.size() + b0.size() << '\n';
		for (auto p : c1) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
		for (auto p : b0) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
	}
}