#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 300000;
typedef long long lld;
lld S[MAXN+1], X[MAXN+1]; // S : prefix sum
vector<int> CX, CY;
int N, M, a, b;
 
void input(){
    scanf("%d", &N);
    CX.resize(N);
    for (int i=0; i<N; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        X[i] = y;
        CX[i] = x;
    }
    scanf("%d", &M);
    CY.resize(M);
    for (int i=0; i<M; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        CY[i] = x;
        S[i+1] = S[i] + y;
    }
    scanf("%d", &a);
    scanf("%d", &b);
}
 
lld solve(){
    lld ans = 0;
    for (int i=0; i<N; i++){
        int s = lower_bound(CY.begin(), CY.end(), CX[i]+a) - CY.begin();
        int e = lower_bound(CY.begin(), CY.end(), CX[i]+b+1) - CY.begin();
        ans += X[i] * (S[e] - S[s]);
    }
    return ans;
}
 
int main(){
    input();
    printf("%lld\n", solve());
}
