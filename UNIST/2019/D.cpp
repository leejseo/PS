#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1'000'000'007;

bool debug = false; //true;

char S[100005][105];
char A[] = "UNIST";
int N;
ll D[100005][6];

void input(){
    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> S[i];
}

void init(){
    for (int i=0; i<=N; i++) D[i][0] = 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    init();
    for (int i=1; i<=N; i++){
        for (int j=1; j<=5; j++){
            D[i][j] = D[i-1][j];
            int sl = strlen(S[i]);
            for (int k=1; k<=min(j, sl); k++){
                bool flag = true;
                for (int l=0; l<k; l++){
                    if (S[i][l] != A[j-k+l]){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    D[i][j] += D[i-1][j-k];
                    D[i][j] %= mod;
                }
            }
        }
    }
    if (debug){
        for (int i=1; i<=N; i++){
            for (int j=0; j<=5; j++){
                cout << D[i][j] << ' ';
            }
            cout << endl;
        }
    }
    cout << D[N][5] << endl;
}
