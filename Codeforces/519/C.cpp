#include <bits/stdc++.h>
using namespace std;

int N;
char s[1001];
int A[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> s;
	N = strlen(s);
	for (int i=1; i<N; i++){
		if (s[i] == 'a'){
			A[i-1] += 1;
			A[i] += 1;
		}
	}
	for (int i=0; i<N; i++) cout << A[i]%2 << ' ';
	cout << endl;
}
