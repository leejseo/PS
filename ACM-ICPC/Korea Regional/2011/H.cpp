#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, T;
int adj[1001][1001];
ll ans, cnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        cin >> N;
        ans = cnt = 0;
        memset(adj, -1, sizeof(adj));
        for (int i=1; i<N; i++){
            for (int j=i+1; j<=N; j++){
                cin >> adj[i][j];
                adj[j][i] = adj[i][j];
            }
        }
        for (int i=1; i<=N; i++){
            ll a = 0, b = 0;
            for (int j=1; j<=N; j++){
                if (adj[i][j] == 1) ++a;
                else if (adj[i][j] == 0) ++b;
            }
            cnt += a * b;
        }
        ans = N*(N-1)*(N-2);
        ans /= 6;
        cout << ans - cnt /2 << '\n';
    }
}
