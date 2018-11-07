#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> L;
vector<int> S;

bool check(int st, int goal){
	if (st == n) return true;
	int cnt = 0;
	int ed = -1;
	for (int i=st; i<n; i++){
		cnt += L[i];
		ed = i;
		if (i == n-1) break;
		if (L[i+1] == 0) continue;
		if (cnt >= goal) break;
	}
	if (cnt != goal) return false;
	return check(ed+1, goal);
}

int main(){
	scanf("%d", &n);
	L.resize(n);
	S.resize(n+1);
	S[0] = 0;
	for (int i=0; i<n; i++){
		scanf("%1d", &L[i]);
		S[i] += L[i];
		S[i+1] = S[i];
	}
	if (S[n-1] == 0){
		printf("YES\n");
		return 0;
	}
	for (int i=0; i<n; i++){
		if (S[i] == S[n-1]){
			printf("NO\n");
			return 0;
		}	
		if (check(0, S[i])){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
