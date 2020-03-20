#include <bits/stdc++.h>
using namespace std;

int N, W, A[5005];

bool chk[800001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> W >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    sort(A, A+N);
    for (int i=0; i<N-1; i++) assert(A[i] != A[i+1]);
    for (int k=0; k<N; k++){
        for (int l=k+1; l<N; l++){
            if (A[k]+A[l] > W) break;
            if (chk[W-A[k]-A[l]]){
                cout << "YES" << endl;
                return 0;
            }
        }
        for (int j=0; j<k; j++){
            chk[A[j]+A[k]] = true;
        }
    }
    cout << "NO" << endl;
}
