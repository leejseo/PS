#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;

vector<vector<int>> E;

int res[100005], org[100005], cur[100005];
int T[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i=1; i<=M; i++){
        int l; cin >> l;
        vector<int> input;
        while (l--){
            int u; cin >> u;
            input.push_back(u);
        }
        E.push_back(input);
    }
    for (int i=1; i<=N; i++) cin >> res[i];
    for (int i=1; i<=N; i++){
        if (res[i] == 0) T[i] = M;
    }
    reverse(E.begin(), E.end());
    for (int i=0; i<M; i++){
        bool flag = false;
        for (auto u : E[i]){
            if (T[u] != 0){
                flag = true;
                break;
            }
        }
        if (flag){
            for (auto u : E[i]){
                T[u] = max(T[u], M-i);
            }
        }
    }
    for (int i=1; i<=N; i++) if (T[i] == 0) org[i] = cur[i] = 1;
    reverse(E.begin(), E.end());
    for (int i=0; i<M; i++){
        int O = 0;
        for (auto u : E[i]) O |= cur[u];
        if (O) for (auto u : E[i]) cur[u] = 1;
    }
    for (int i=1; i<=N; i++) if (cur[i] != res[i]){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES\n";
    for (int i=1; i<=N; i++) cout << org[i] << ' ';
    cout << endl;
}
