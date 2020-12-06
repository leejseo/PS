#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1E18;

int N, M, Q;
ll A[250005], B[250005];
ll X[250005], Y[250005];
ll cnt[500005];
ll st[500005], ed[500005];

typedef long long LL;

struct segment_tree{
    vector<LL> tree, flag, mx;
    void init(int n){
        tree.resize(4 * n + 5);
        flag.resize(4 * n + 5);
        mx.resize(4 * n + 5);
    }
    void udt(LL v, int y){
        tree[y] += v;
        mx[y] += v;
        flag[y] += v;
    }
    void spread(int x){
        udt(flag[x], 2 * x);
        udt(flag[x], 2 * x + 1);
        flag[x] = 0;
    }
    void range_sum_update(int x, int l, int r, int s, int e, LL v){
        if(l != r)    spread(x);
        if(e < l || r < s)    return;
        if(s <= l && r <= e){
            udt(v, x);
            return;
        }
        int mid = (l + r) >> 1;
        range_sum_update(2 * x, l, mid, s, e, v);
        range_sum_update(2 * x + 1, mid + 1, r, s, e, v);
        mx[x] = max(mx[2 * x], mx[2 * x + 1]);
    }
    LL get_range_max(int x, int l, int r, int s, int e){
        if(l != r)    spread(x);
        if(e < l || r < s)    return -INF;
        if(s <= l && r <= e){
            return mx[x];
        }
        int mid = (l + r) >> 1;
        return max(get_range_max(2 * x, l, mid, s, e), get_range_max(2 * x + 1, mid + 1, r, s, e));
    }
} seg;

void print(bool x){
    if (x) cout << 1 << '\n';
    else cout << 0 << '\n';
}

void query1(int idx){
    // 세그먼트 트리 st[A[idx]] 번째 ~ 끝 +1
    seg.range_sum_update(1, 1, N, st[A[idx]], N, +1);
    ed[A[idx]+1] = st[A[idx]];
    st[A[idx]+1] = min(st[A[idx]+1], ed[A[idx]+1]);
    st[A[idx]]++;
    A[idx]++;
    print(seg.get_range_max(1, 1, N, 1, N) <= 0);
}

void query2(int idx){
    // 세그먼트 트리 ed[A[idx]] 번째 ~ 끝 -1
    seg.range_sum_update(1, 1, N, ed[A[idx]], N, -1);
    st[A[idx]-1] = ed[A[idx]];
    ed[A[idx]-1] = max(ed[A[idx]-1], st[A[idx]-1]);
    ed[A[idx]]--;
    A[idx]--;
    print(seg.get_range_max(1, 1, N, 1, N) <= 0);
}

void query3(int jdx){
    B[jdx]++;
    //세그먼트 트리 B[jdx]번째 ~ N번째 -1
    seg.range_sum_update(1, 1, N, B[jdx], N, -1);
    print(seg.get_range_max(1, 1, N, 1, N) <= 0);
}

void query4(int jdx){
    seg.range_sum_update(1, 1, N, B[jdx], N, 1);
    //세그먼트 트리 B[jdx]번째 ~ N번째 +1
    B[jdx]--;
    print(seg.get_range_max(1, 1, N, 1, N) <= 0);
}

void query(int k, int i){
    if (k == 1) query1(i);
    if (k == 2) query2(i);
    if (k == 3) query3(i);
    if (k == 4) query4(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    seg.init(N);
    for (int i=1; i<=N; i++){
        cin >> A[i];
        X[i] = A[i];
    }
    for (int i=0; i<=500000; i++){
        st[i] = INF;
        ed[i] = -INF;
    }
    for (int j=1; j<=M; j++){
        cin >> B[j];
        Y[j] = B[j];
    }
    sort(X+1, X+N+1);
    reverse(X+1, X+N+1);
    for (ll i=1; i<=N; i++){
        st[X[i]] = min(st[X[i]], i);
        ed[X[i]] = max(st[X[i]], i);
    }
    sort(Y+1, Y+M+1);
    for (int i=1; i<=N; i++){
        ll cur = M - (lower_bound(Y+1, Y+M+1, i) - (Y+1));
        X[i] -= cur;
        seg.range_sum_update(1, 1, N, i, N, X[i]);
    }
    //for (int i=1; i<=N; i++) cout << seg.get_range_max(1, 1, N, i, i) << ' ';
    //cout << '\n';
    cin >> Q;
    for (int i=0; i<Q; i++){
        int k, idx; cin >> k >> idx;
        query(k, idx);
        //for (int i=1; i<=N; i++) cout << seg.get_range_max(1, 1, N, i, i) << ' ';
        //cout << '\n';
    }
}