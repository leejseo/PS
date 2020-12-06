#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1E15;

int N, M;

ll tree[2005][2005];
ll S[2005];

void update_y(int x, int y, ll val){
    while (y <= N){
        tree[x][y] = max(tree[x][y], val);
        y += (y & -y);
    }
}

void update(int x, int y, ll val){
    while (x <= N){
        update_y(x, y, val);
        x += (x & -x);
    }
}

ll query_y(int x, int y){
    ll ret = -INF;
    while (y){
        ret = max(ret, tree[x][y]);
        y -= (y & -y);
    }
    return ret;
}

ll query(int x, int y){
    ll ret = -INF;
    while (x){
        ret = max(ret, query_y(x, y));
        x -= (x & -x);
    }
    return ret;
}

vector<tuple<ll, ll, ll, ll>> A;

ll ans[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i=0; i<=N; i++){
        for (int j=0; j<=N; j++){
            tree[i][j] = -INF;
        }
    }
    for (int i=1; i<=N; i++){
        cin >> S[i];
        S[i] += S[i-1];
    }
    for (int j=0; j<N; j++){
        for (int i=j+1; i<=N; i++){
            A.push_back({S[i] - S[j], 0, N-j, i});
        }
    }
    for (int i=1; i<=M; i++){
        ll s, e, x;
        cin >> s >> e >> x;
        A.push_back({x, i, N-s+1, e});
    }
    sort(A.begin(), A.end());
    for (auto [x, t, s, e]: A){
        if (t == 0){
            update(s, e, x);
        }
        else{
            ans[t] = query(s, e);
        }
    }
    for (int i=1; i<=M; i++){
        if (ans[i] == -INF) cout << "NONE" << '\n';
        else cout << ans[i] << '\n';
    }
}