#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll D[2005][2005], T[2005][2005], F[2005][2005];
int N; ll K;
ll L[2005], R[2005], A[2005];

ll ans[2005];

void compute(int st){
    ll lft = K;
    for (int i=st; i<=N; i++){
        ll req = max(0LL, (A[i]-1-lft)/K+1);
        //cout << lft << ' ' << req << endl;
        if (A[i] <= lft) req = 0;
        if (R[i] - L[i] < req) return;
        if (L[i] + req + 1 <= L[i+1]) T[st][i] = 1;
        lft = (lft - A[i] + K*(ll)1E9) % K;
        F[st][i] = lft;
        D[st][i] = max(0LL, D[st][i-1]) +  A[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    memset(D, -1, sizeof(D));
    for (int i=1; i<=N; i++) cin >> L[i] >> R[i] >> A[i];
    L[N+1] = 1E18;
    for (int i=1; i<=N; i++){
        compute(i);
        if (T[1][i]){
            if (D[1][i] < 0) continue;
            ans[i] = D[1][i];
            if (i != N) ans[i] += F[1][i];
        }
        else ans[i] = 1E18;
    }
    for (int i=1; i<=N; i++){
        if (ans[i-1] == 1E18) continue;
        for (int j=i; j<=N; j++){
            if (j == N || T[i][j]){
                if (D[i][j] < 0) continue;
                ll cur = ans[i-1] + D[i][j];
                if (j != N) cur += F[i][j];
                ans[j] = min(ans[j], cur);
            }
        }
    }
    if (ans[N] >= 1E18) cout << -1 << endl;
    else cout << ans[N] << endl;
}