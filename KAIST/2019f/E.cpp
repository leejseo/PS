#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;

char C[513][513];
vector<int> adj[513];
int T, N;

vector<int> ans;
vector<int> W;
int cnt[659];

void solve(vector<int> &V, int num){
    int n = V.size();
    random_shuffle(V.begin(), V.end());
    if (num == 1){
        ans.push_back(V[0]);
        return;
    }
    memset(cnt, 0, sizeof(int)*(n+5));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (C[V[i]][V[j]] == 'W'){
                cnt[i]++;
            }
        }
    }
    int maxval = 0, idx = -1;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (cnt[i] > maxval){
                maxval = cnt[i];
                idx = i;
            }
        }
    }
    ans.push_back(V[idx]);
    vector<int> K;
    for (int i=0; i<n; i++){
        if (i == idx) continue;
        if (C[V[idx]][V[i]] == 'W') K.push_back(V[i]);
    }
    V.clear();
    solve(K, num-1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(0x0497);
    cin >> T;
    while (T--){
        cin >> N;
        W.clear();
        for (int i=0; i<N; i++){
            cin >> C[i];
            W.push_back(i);
        }
        ans.clear();
        int K = log2(N);
        K++;
        solve(W, K);
        for (int i : ans) cout << i+1 << ' ';
        cout << '\n';
    }
}