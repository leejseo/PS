#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int N;
string S;

vector<int> A;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        cin >> N >> S;
        if (N <= 2){
            cout << 1 << '\n';
            continue;
        }
        A.clear();
        for (int i=0; i<N; i++){
            if (A.empty() || S[i] != S[i-1]) A.push_back(1);
            else A[A.size() - 1]++;
        }
        int K = A.size();
        int i = 0;
        int t;
        for (t=0; t<K; t++){
            if (i == t-1) i++;
            if (A[i] >= 2){
                A[i] -= 1; 
                continue;
            }
            while (i < K){
                if (A[i] >= 2){
                    A[i] -= 1;
                    break;
                }
                i++;
            }
            if (i >= K) break;
        }
        int ans = t;
        ans += (K - t + 1)/2;
        cout << ans << '\n';
    }
}