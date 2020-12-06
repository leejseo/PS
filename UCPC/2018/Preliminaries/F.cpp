#include <bits/stdc++.h>
using namespace std;
 
typedef long long lld;
 
const lld mod = 1000000007;
lld ans;
 
typedef pair<int, int> pii;
 
int N, M, C;
vector<int> adj[200001];
vector<pii> query, color;
int par[200001], siz[200001], lev[200001];
int num[200001], chain[200001], tail[200001];
int m;
 
struct SegmentTree{
    int tree[524288], lazy[524288];
    SegmentTree(){
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
    }
    void update_lazy(int node, int begin, int end){
        if (lazy[node] != 0){
            tree[node] += lazy[node]*(end-begin+1);
            if (begin != end){
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
        }
        lazy[node] = 0;
    }
    int query(int node, int begin, int end, int left, int right){
        update_lazy(node, begin, end);
        if (end < left || right < begin) return 0;
        if (left <= begin && end <= right) return tree[node];
        int mid = (begin + end) >> 1;
        if (begin == end) return tree[node];
        int l = query(node*2, begin, mid, left, right);
        int r = query(node*2+1, mid+1, end, left, right);
        return l + r;
    }
    void update(int node, int begin, int end, int left, int right, int val){
        update_lazy(node, begin, end);
        if (end < left || right < begin) return;
        if (left <= begin && end <= right){
            tree[node] += (end-begin+1)*val;
            if (begin != end){
                lazy[node*2] += val;
                lazy[node*2+1] += val;
            }
            return;
        }
        int mid = (begin + end) >> 1;
        update(node*2, begin, mid, left, right, val);
        update(node*2+1, mid+1, end, left, right, val);
        tree[node] = tree[node*2]+tree[node*2+1];
        return;
    }
} seg;
 
/***************************************
 ***** Heavy - Light Decomposition *****
 ***************************************/
 
void dfs(int v, int p){
    par[v] = p;
    siz[v] = 1;
    for (auto &w : adj[v]){
        if (w != p){
            lev[w] = lev[v] + 1;
            dfs(w, v);
            siz[v] += siz[w];      
        }
    }
}
 
void hld(int v, int p, int n){
    num[v] = ++m;
    chain[m] = n;
    tail[n] = m;
    int i = -1;
    for (auto &w : adj[v]){
        if (w == p) continue;
        if (i == -1 || siz[w] > siz[i]) i = w;
    }
    if (i != -1) hld(i, v, n);
    for (auto &w : adj[v]){
        if (w != p && w != i){
            hld(w, v, w);
        }
    }
}
 
int lca(int v, int w){
    while (chain[num[v]] != chain[num[w]]){
        int v1 = chain[num[v]];
        int w1 = chain[num[w]];
        if (lev[v1] > lev[w1]) v = par[v1];
        else w = par[w1];
    }
    return lev[v] > lev[w] ? w : v;
}
 
void input(){
    cin >> N >> M >> C;
    for (int i=1; i<=N; i++){
        int c;
        cin >> c;
        color.push_back(pii(c, i));
    }
    for (int i=1; i<N; i++){
        int v, w;
        cin >> v >> w;
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    for (int i=0; i<M; i++){
        int v, c;
        cin >> v >> c;
        query.push_back(pii(c, v));
    }
}
 
void update(int v){
    while (chain[num[1]] != chain[num[v]]){
        seg.update(1, 1, N, num[chain[num[v]]], num[v], 1);
        v = par[chain[num[v]]];
    }
    seg.update(1, 1, N, num[1], num[v], 1);
}
 
inline int compute(int v){
    return seg.query(1, 1, N, num[v], num[v]);
}
 
void solve(){
    int numColor = 0, numQuery = 0;
    for (int i=1; i<=C; i++){
        while (numColor < N && color[numColor].first == i){
            update(color[numColor].second);
            numColor++;
        }
        while (numQuery < M && query[numQuery].first == i){
            ans += compute(query[numQuery].second);
            ans = ans % mod;
            numQuery++;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    input();
    dfs(1, 0);
    hld(1, 0, 1);
    sort(color.begin(), color.end());
    sort(query.begin(), query.end());
    solve();
    cout << ans << endl;
}
