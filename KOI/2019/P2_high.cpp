#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline int dmap(char c){
	if (c == '(') return 1;
	if (c == ')') return 2;
	if (c == '{') return 3;
	if (c == '}') return 4;
	if (c == '[') return 5;
	if (c == ']') return 6;
}

bool _less(const string &s, const string &t){
	// true <=> dmap(s) < dmap(t)
	if (s == "1") return false;
	if (t == "1") return true;
	if (s.size() != t.size())
		return s.size() < t.size();
	int n = s.size();
	for (int i=0; i<n; i++){
		if (dmap(s[i]) != dmap(t[i])){
			return dmap(s[i]) < dmap(t[i]);
		}
	}
	return false;
}

int T, M, N = 1000;
vector<string> D(1001, "1");

void proc(){
	D[0] = "", D[1] = "()", D[2] = "{}", D[3] = "[]";
	for (int i=4; i<=N; i++){
		for (int j=1; j<i; j++){
			if (_less(D[j]+D[i-j], D[i]))
				D[i] = D[j]+D[i-j];
		}
		if (i % 2 == 0){
			if (_less("("+D[i/2]+")", D[i]))
				D[i] = "("+D[i/2]+")";
		}
		if (i % 3 == 0){
			if (_less("{"+D[i/3]+"}", D[i]))
				D[i] = "{"+D[i/3]+"}";
		}
		if (i % 5 == 0){
			if (_less("["+D[i/5]+"]", D[i]))
				D[i] = "["+D[i/5]+"]";
		}
	}
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
	proc();
	cin >> T;
	while (T--){
		cin >> M;
		cout << D[M] << '\n';
	}
}