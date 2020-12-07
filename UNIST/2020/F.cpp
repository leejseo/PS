#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
ll H[200005];
ll T[200005];
int ridx[200005], lidx[200005];

ll tree[524288];

void update(int n, int l, int r, int i, ll x){
    if (i < l || r < i) return;
    if (l == r){
        tree[n] = x;
        return;
    }
    int m = (l+r)/2;
    update(n*2, l, m, i, x);
    update(n*2+1, m+1, r, i, x);
    tree[n] = max(tree[n*2], tree[n*2+1]);
}

ll query(int n, int l, int r, int s, int e){
    if (e < l || r < s) return 0;
    if (s <= l && r <= e) return tree[n];
    int m = (l+r)/2;
    return max(
        query(n*2, l, m, s, e),
        query(n*2+1, m+1, r, s, e)
    );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=0; i<N; i++) cin >> H[i];
    for (int i=1; i<N; i++) cin >> T[i];
    {
        ll ctime = 0;
        for (int i=0; i<N; i++){
            if (i != 0){
                if (ridx[i-1] > i){
                    ridx[i] = ridx[i-1];
                    ctime -= T[i];
                }
                else{
                    ctime = 0;
                    ridx[i] = i;
                }
            }
            while (ridx[i] < N-1){
                if (ctime + T[ridx[i]+1] <= H[ridx[i]+1]) ctime += T[++ridx[i]];
                else break;
            }
        }
    }
    {
        ll ctime = 0;
        lidx[N-1] = N-1;
        for (int i=N-1; i>=0; i--){
            if (i != N-1){
                if (lidx[i+1] < i){
                    lidx[i] = lidx[i+1];
                    ctime -= T[i+1];
                }
                else{
                    ctime = 0;
                    lidx[i] = i;
                }
            }
            while (lidx[i] > 0){
                if (ctime + T[lidx[i]] <= H[lidx[i]-1]) ctime += T[lidx[i]--];
                else break;
            }
        }
    }
    for (int i=0; i<N; i++) update(1, 0, N, i, H[i]);
    for (int i=0; i<N; i++){
        if (i) cout << ' ';
        cout << query(1, 0, N, lidx[i], ridx[i]);
    }
    cout << endl;
}
