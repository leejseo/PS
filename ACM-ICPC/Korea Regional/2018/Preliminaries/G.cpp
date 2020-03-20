#include <bits/stdc++.h>
using namespace std;

int D[101];
int L[101];
int N, k;

int main(){
	scanf("%d%d", &N, &k);
	for (int i=0; i<N; i++) scanf("%d", L+i);
	for (int i=0; i<N; i++) D[i] = 1;
	int ans = 0;
	for (int i=0; i<N; i++){
		for (int j=0; j<i; j++){
			if (L[j] > L[i]) D[i] = max(D[i], D[j]+1);
		}
		ans = max(ans, D[i]);
	}
	printf(ans <= k ? "YES" : "NO");
	printf("\n");
}
