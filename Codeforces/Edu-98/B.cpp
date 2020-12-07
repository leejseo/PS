#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int N;
ll A[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        cin >> N;
        for (int i=1; i<=N; i++) cin >> A[i];
        ll sum = 0;
        for (int i=1; i<=N; i++) sum += A[i];
        ll ans = (sum + N- 2LL)/(N-1LL);
        for (int i=1; i<=N; i++) ans = max(ans, A[i]);
        cout << ans * (N-1LL) - sum << '\n';
    }
}