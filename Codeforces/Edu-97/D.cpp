#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int N;
int A[200005];
queue<int> Q;
vector<int> adj[200005];

int dfs(int x){
    int ret = -1;
    for (int y : adj[x]) ret = max(ret, dfs(y));
    return ret+1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        cin >> N;
        for (int i=1; i<=N; i++) cin >> A[i];
        for (int i=1; i<=N; i++) adj[i].clear();
        Q = queue<int>();
        Q.push(1);
        for (int i=2; i<=N; i++){
            if (A[i] < A[i-1]) Q.pop();
            adj[Q.front()].push_back(i);
            Q.push(i);
        }
        cout << dfs(1) << '\n';
    }
}