#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string S, T;

int N, M;
int nxt[100005][26];
bool chk[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S >> T;
    N = S.length(), M = T.length();
    for (char c : T) chk[c-'a'] = true;
    for (char c : S) if (!chk[c-'a']){
        cout << -1 << endl;
        return 0;
    }
    memset(nxt, -1, sizeof(nxt));
    for (int i=M-1; i>=0; i--){
        for (int j=0; j<26; j++) nxt[i][j] = nxt[i+1][j];
        nxt[i][T[i]-'a'] = i+1;
    }
    int cnt = 1, idx = 0;
    for (int c : S){
        idx = nxt[idx][c-'a'];
        if (idx == -1){
            cnt++; idx = nxt[0][c-'a'];
        }
    }
    cout << cnt << endl;
}