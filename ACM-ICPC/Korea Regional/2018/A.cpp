#include <bits/stdc++.h>
using namespace std;

struct Rect{
    int x1, x2, y1, y2;
} A[100005];

int N, M;
vector<int> Y;

inline int get_index(int y){
    return lower_bound(Y.begin(), Y.end(), y) - Y.begin();
}

int tree[524288], lazy[524288];

void update_lazy(int n, int b, int e){
    if (lazy[n] != 0){
        tree[n] += lazy[n];
        if (b != e){
            lazy[2*n] += lazy[n];
            lazy[2*n+1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

int update(int n, int b, int e, int l, int r, int v){
    if (lazy[n] != 0){
        update_lazy(n, b, e);
    }
    if (r < b || e < l) return tree[n];
    if (l <= b && e <= r){
        tree[n]+= v;
        if (b != e){
            lazy[2*n]+=v;
            lazy[2*n+1]+=v;
        }
        return tree[n];
    }
    int mid = (b+e)/2;
    int v1 = update(2*n, b, mid, l, r, v);
    int v2 = update(2*n+1, mid+1, e, l, r, v);
    return tree[n] = max(v1, v2);
}

vector<int> S[200005], T[200005];
int K[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i].x1 >> A[i].y2 >> A[i].x2 >> A[i].y1;
        Y.push_back(A[i].y1);
        Y.push_back(A[i].y2);
    }
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    M = Y.size();
    for (int i=0; i<N; i++){
        A[i].y1 = get_index(A[i].y1);
        A[i].y2 = get_index(A[i].y2);
        S[A[i].y1].push_back(i);
        T[A[i].y2+1].push_back(i);
        K[A[i].y1]++;
        K[A[i].y2+1]--;
        update(1, 0, M, A[i].y1, A[i].y2, 1);
    }
    int ans = 0;
    for (int i=0; i<M; i++){
        if (i) K[i] += K[i-1];
        for (int j : S[i]){
            update(1, 0, M, A[j].y1, A[j].y2, -1);
        }
        for (int j : T[i]){
            update(1, 0, M, A[j].y1, A[j].y2, 1);
        }
        update_lazy(1, 0, M);
        ans = max(ans, K[i]+tree[1]);
    }
    cout << ans << endl;
}
