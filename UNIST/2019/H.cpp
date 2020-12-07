#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, K;
ll D[10005][1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i=0; i<K; i++){
        ll x, y; cin >> x >> y;
        for (int t=0; t<=N; t++){
            D[t][i+1] = max(D[t][i+1], D[t][i]);
            if (t == 0) continue;
            D[t][i+1] = max(D[t][i+1], D[t-1][i+1]);
            if (t - y < 0) continue;
            D[t][i+1] = max(D[t][i+1], D[t-y][i] + x);
        }
    }
    cout << D[N][K] << endl;
}