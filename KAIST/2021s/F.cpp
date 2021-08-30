#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int A[1048576], N;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i=0; i<(1<<N); i++) cin >> A[i];
	for (int s=0; s<(1<<N); s++){
		for (int i=0; i<N; i++){
			for (int j=0; j<i; j++){
				int t = s ^ (1 << i) ^ (1 << j);
				if (A[s] + A[t] < A[s&t] + A[s|t]){
					cout << s << ' ' << t << endl;
					return 0;
				}
			}
		}
	}	
	cout << -1 << endl;
}
