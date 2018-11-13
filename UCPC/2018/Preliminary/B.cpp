#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
priority_queue<lld> pq;
int n, m, temp;
lld S, u, v;
int main(){
	scanf("%d%d", &n, &m);
	while (n--){
		scanf("%d", &temp);
		pq.push(-temp);
		S += temp;
	}
	while (m--){
		u = pq.top(); pq.pop();
		v = pq.top(); pq.pop();
		S += -u-v;
		pq.push(u+v); pq.push(u+v);
	}
	printf("%lld\n", S);
}
