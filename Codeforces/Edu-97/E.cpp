#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int N, K;
ll A[500005];
ll B[500005];

vector<ll> X;
vector<ll> dp;

int LIS(){
    int n = X.size();
    dp.clear();
    dp.push_back(-1E9);
    for (int i=0; i<n; i++){
        if (dp.back() <= X[i]){
            dp.push_back(X[i]);
        }
        else{
            auto it = lower_bound(dp.begin(), dp.end(), X[i]+1);
            *it = X[i];
        }
    }
    return dp.size() - 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> A[i];
    A[0] = -1E9;
    if (K == 0){
        for (int i=1; i<=N; i++) X.push_back(A[i] - i);
        cout << N - LIS() << endl;
        return 0;
    }
    for (int j=1; j<=K; j++) cin >> B[j];
    for (int j=1; j<=K; j++){
        if (A[B[j-1]] + B[j] - B[j-1] > A[B[j]]){
            cout << -1 << endl;
            return 0;
        }
    }
    int ans = N-K;
    for (int j=1; j<=K; j++){
        int l = B[j-1], r = B[j];
        X.clear();
        for (int k=1; k<r-l; k++){
            int i = l + k;
            if (A[i] < A[l] + k || A[i] > A[r] - (r-l) + k){
                continue;
            }
            X.push_back(A[i] - (A[l] + k));
        }
        ans -= LIS();
    }
    if (B[K] != N){
        int l = B[K];
        X.clear();
        for (int k=1; k<=N-l; k++){
            int i = l + k;
            if (A[i] < A[l] + k) continue;
            X.push_back(A[i] - (A[l] + k));
        }
        ans -= LIS();
    }
    cout << ans << endl;
}