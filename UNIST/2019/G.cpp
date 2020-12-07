#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;

const ll mod1 = (1E9)+7, mod2 = (1E9)+9;
const ll x1 = 3, x2 = 26;

char S[200005];
ll h1[200005], h2[200005];

pair<pair<ll, ll>, int> A[200005];

ll powmod(ll a, ll b, ll MOD){
	ll base = a, ret = 1;
	while(b>0){
		if(b&1){
			b--;
			ret = (ret*base)%MOD;
		}
		else{
			b/=2;
			base = (base*base)%MOD;
		}
	}
	return ret;
}

bool able(int len){
	//cout << len << endl;
	ll inv1 = powmod(x1, len, mod1);
	ll inv2 = powmod(x2, len, mod2);
	for (int i=0; i<=N-len; i++){
		A[i].first.first = (h1[i+len] - ((h1[i] * inv1)%mod1) + mod1)%mod1;
		A[i].first.second = (h2[i+len] - ((h2[i] * inv2)%mod2) + mod2)%mod2;
		A[i].second = i;
	}
	sort(A, A+N-len+1);
	pair<ll, ll> cur = {-1, -1};
	int idx = -1;
	for (int i=0; i<=N-len; i++){
		//cout << A[i].first.first << ' ' << A[i].first.second << endl;
		if (cur == A[i].first){
			if (A[i].second - idx >= len) return true;
		}
		else{
			cur = A[i].first;
			idx = A[i].second;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> S;
	N = strlen(S);
	for (int i=0; i<N; i++){
		h1[i+1] = ((h1[i]*x1) % mod1 + (ll)S[i])%mod1;
		h2[i+1] = ((h2[i]*x2) % mod2 + (ll)S[i])%mod2;
	}
	int lo = 0, hi = N;
	while (lo+1 < hi){
		int mid = (lo + hi) / 2;
		if (able(mid)) lo = mid;
		else hi = mid;
	}
	cout << (lo ? lo : -1) << '\n';
}
