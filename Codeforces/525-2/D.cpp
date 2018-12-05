#include <bits/stdc++.h>
using namespace std;

int P[30];

inline void query(int i, int j){
	printf("? %d %d\n", i, j);
	fflush(stdout);
}

inline int result(){
	int n;
	scanf("%d", &n);
	return n;
}

int main(){
	for (int i=0; i<30; i++) P[i] = 1 << i;
	query(0, 0);
	int r = result();
	int i=29;
	int a = 0, b = 0;
	for(;i>=0;i--){
		if (r > 0){
			query(a, b+P[i]);
			int nr = result();
			if (nr == 0){
				b += P[i];
				r = 0;
				continue;
			}
			query(a+P[i], b+P[i]);
			int nnr = result();
			if (nr == -1){
				// 1 0 or 0 0
				if (nnr == 1){
					a += P[i];
					b += P[i];
					r = 1;
					continue;
				}
				//nnr == -1
				b += P[i];
				r = -1;
				continue;
			}
			// 1 1 or 1 0
			if (nnr == 1){
				r = 1;
				continue;
			}
			b += P[i];
			r = 1;
			continue;
		}
		if (r == 0){
			query(a+P[i], b);
			int nr = result();
			if (nr == 1){
				a += P[i];
				b += P[i];
				continue;
			}
			continue;
		}
		// 00 11 01
		query(a+P[i], b);
		int nr = result();
		if (nr == 0){
			a += P[i];
			r = 0;
			continue;
		}
		query(a+P[i], b+P[i]);
		int nnr = result();
		if (nr > 0){
			if (nnr < 0){
				a += P[i];
				b += P[i];
				r = -1;
				continue;
			}
			a += P[i];
			r = 1;
			continue;
		}
		if (nnr == -1){
			r = -1;
			continue;
		}
		a += P[i];
		r = -1;
		continue;
	}
	int p = 0;
	for (int i=0; i<30; i++) p += P[i];
	printf("! %d %d\n", p-a, p-b);
}
