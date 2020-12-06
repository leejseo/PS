#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;
char A[505][505];

int ans;
bool flag=true;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    for (int i=0; i<N&&flag; i++){
        int j = N - 1 - i;
        if (i > j) continue;
        if (i == j){
            for (int k=0; k<M&&flag; k++){
                int l = M - 1 - k;
                if (k == l){
                    if (A[i][k] != '8'){
                        flag = false;
                        break;
                    }
                }
                else if (k < l){
                    if ((A[i][k] == '8') != (A[i][l] == '8')){
                        flag = false;
                        break;
                    }
                    if (A[i][k] == '8'){
                        continue;
                    }
                    if ((A[i][k] == '7') != (A[i][l] == '7')){
                        flag = false;
                        break;
                    }
                    if (A[i][k] == '7'){
                        ans++; continue;
                    }
                    if (A[i][k] == A[i][l]) ans++;
                }
            }
            continue;
        }
        // i != j
        for (int k=0; k<M&&flag; k++){
            int l = M - 1 - k;
            if ((A[i][k] == '8') != (A[j][l] == '8')){
                flag = false;
                break;
            }
            if (A[i][k] == '8'){
                continue;
            }
            if ((A[i][k] == '7') != (A[j][l] == '7')){
                flag = false;
                break;
            }
            if (A[i][k] == '7'){
                ans++; continue;
            }
            if (A[i][k] == A[j][l]) ans++;
        }
    }
    if (!flag){
        cout << "-1" << endl;
        return 0;
    }
    cout << ans << endl;
}