#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

string S;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        cin >> S;
        int N = S.length();
        int c = 0, d = 0, ans = 0;
        for (int i=0; i<N; i++){
            if (S[i] == '('){
                c++; continue;
            }
            else if (S[i] == ')'){
                if (c != 0) ans++;
                c--;
                c = max(c, 0);
            }
            else if (S[i] == '['){
                d++; continue;
            }
            else if (S[i] == ']'){
                if (d != 0) ans++;
                d--;
                d = max(d, 0);
            }
        }
        cout << ans << '\n';
    }
}