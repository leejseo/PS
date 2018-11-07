#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
vector<int> A;
int N;
int temp[2];
int S[300001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	lld temps;
	cin >> N;
	A.resize(N);
	temp[0] = 1;
	//lld sena = 0;
	for (int i=0; i<N; i++){
		cin >> temps;
		A[i] = __builtin_popcountll(temps);
		//if (A[i] % 2 == 0) ++sena;
	}
	int s = 0;
	for (int i=0; i<N; i++){
		S[i+1] = S[i] + A[i];
		//cout << A[i] << '\n';
		s = (s + A[i])%2;
		temp[s]++;
	}
	lld even = (lld) temp[0];
	lld odd = (lld) temp[1];
	lld ans = (even * (even - 1LL) / 2LL) + (odd * (odd - 1LL) / 2LL);
	lld sena = 0;
	for (int i=0; i<N; i++){
		int l=i-1, r=i+1;
		while (true){
			if (l < 0){
				++l;
				break;
			}
			if (i - A[i] > l){
				++l;
				break;
			}
			if (A[i] <= A[l]){
				++l;
				break;
			}
			--l;
		}
		while (true){
			if (r >= N){
				--r;
				break;
			}
			if (i + A[i] < r){
				--r;
				break;
			}
			if (A[i] <= A[r]){
				--r;
				break;
			}
			++r;
		}
		for (int k=l; k<=i; k++){
			for (int h=i; h<=r; h++){
				if (S[h+1] - S[k] >= 2*A[i]) break;
				if ((S[h+1] - S[k]) %2 == 0)++sena;
			}
		}
	}
	cout << ans - sena << '\n';
}
