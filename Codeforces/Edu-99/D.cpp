#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int N, X;
int A[505];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        cin >> N >> X;
        for (int i=1; i<=N; i++) cin >> A[i];
        int ans = 0;
        for (int i=1; i<N; i++){
            if (A[i] > A[i+1] && A[i] > X){
                int k = i;
                while (k-1 >= 1 && A[k-1] > X) k--;
                for (int j=k; j<=i; j++){
                    if (A[j] > X){
                        swap(X, A[j]);
                        ans++;
                    }
                }
            }
        }
        bool flag = true;
        //for (int i=1; i<=N; i++) cout << A[i] << ' ';
        //cout << '\n';
        for (int i=1; i<N; i++){
            if (A[i] > A[i+1]) flag = false;
        }
        if (flag) cout << ans << '\n';
        else cout << -1 << '\n';
    }
}