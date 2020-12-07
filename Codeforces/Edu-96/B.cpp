#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int N, K;
ll A[200005];
ll ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        ans = 0;
        cin >> N >> K;
        for (int i=0; i<N; i++){
            cin >> A[i];
        }
        sort(A, A+N);
        for (int i=N-K-1; i<N-1; i++) A[N-1] += A[i];
        cout << A[N-1] << '\n';
    }
}