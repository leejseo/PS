#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;

int par[500005];

void init(){
    for (int i=1; i<=N; i++) par[i] = i;
}

int root(int x){
    if (x == par[x]) return x;
    return par[x] = root(par[x]);
}

void merge(int x, int y){
    x = root(x), y = root(y);
    if (x != y) par[x] = y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    init();
    int ans = 0;
    for (int i=1; i<=M; i++){
        int x, y; cin >> x >> y;
        if (root(x) == root(y) && ans == 0){
            ans = i;
        }
        merge(x, y);
    }
    cout << ans << endl;
}