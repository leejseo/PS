#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long lld;

#define int long long

int N;
string S, T;

vector<ll> A[26], B[26];

int X[200005];

struct BIT{
	lld tree[524288];
	const int MAXN = 524288;
	lld sum(int i){
		lld ans = 0;
		while (i > 0){
			ans += tree[i];
			i -= (i & -i);
		}
		return ans;
	}
	void update(int i, lld diff){
		while (i < MAXN){
			tree[i] += diff;
			i += (i & -i);
		}
	}
} tree;

int I[200005];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S;
    T = S;
    reverse(T.begin(), T.end());
    for (int i=0; i<N; i++){
        A[S[i] - 'a'].push_back(i);
        B[T[i] - 'a'].push_back(i);
    }
    ll ans2 = 0;
    for (int i=0; i<26; i++){
        for (int j=0; j<A[i].size(); j++){
            ans2 += abs(A[i][j] - B[i][j]);
            X[A[i][j]+1] = B[i][j]+1;
        }
    }
    int ans = 0;
    for (int i=1; i<=N; i++){
        ans += i - tree.sum(X[i]) - 1;
        tree.update(X[i], 1);
    }
    cout << ans << endl;
}