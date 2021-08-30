#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool board[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    if (N == 1) {
        if (K == 0) {
            cout << "YES" << endl;
            cout << "." << endl;
            return 0;
        }
        if (K == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (N == 2) {
        if (K >= 2) cout << "NO" << endl;
        else if (K == 0) cout << "YES" << endl << ".." << endl << ".." << endl;
        else cout << "YES" << endl << "#." << endl << ".." << endl;
        return 0;
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i == 0 && j == 0) board[i][j] = true;
            else if (i == N-1 && j == N-1) board[i][j] = true;
            else if (i + j == N-1 && 0 < i && i < N-1) board[i][j] = true;
        }
    }
    if (K > N*N-N){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << '\n';
    int cnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (board[i][j]) cout << ".";
            else if (cnt < K) {
                cout << "#";
                cnt++;
            } else {
                cout << ".";
            }
        }
        cout << '\n';
    }
}
