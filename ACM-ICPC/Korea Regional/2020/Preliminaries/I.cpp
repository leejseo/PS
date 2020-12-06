#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll A[10005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=0; i<2*N; i++) cin >> A[i];
    sort(A, A+2*N);
    ll ans = 1E18;
    for (int i=0; i<N; i++) ans = min(ans, A[2*N-1-i]+A[i]);
    cout << ans << endl;
}