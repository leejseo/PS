#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

lld N;

bool check(int K){
	lld goal = N-K;
	lld val = K+1;
	if (goal <= val) return true;
	for (int k=0; k<K; k++){
		goal -= val;
		val += val;
		if (goal <= val) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int k=1; k<=100; k++){
		if (check(k)){
			cout << k << endl;
			return 0;
		}
	}
}
