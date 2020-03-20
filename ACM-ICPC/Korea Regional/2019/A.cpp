#include <bits/stdc++.h>
using namespace std;

int N;
int D[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    D[0] = 1, D[1] = 1;
    for (int i=2; i<=N; i++){
        for (int k=1; k<=1000; k++){
            bool flag = true;
            for (int j=1; j<=N; j++){
                if (i-2*j < 0) break;
                if (D[i-j]-D[i-2*j] == k - D[i-j]){
                    flag = false;
                    break;
                }
            }
            if (flag){
                D[i] = k;
                break;
            }
        }
    }
    cout << D[N] << endl;
}
