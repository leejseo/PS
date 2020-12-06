#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll H[1000005];
vector<pair<ll, ll>> lo, hi, A, B;

ll solve(int s, int e, int l, int r){
    if (s > e) return 0;
    int m = (s + e) >> 1;
    ll ret = -1E18; int k = -1;
    for (int i=l; i<=r; i++){
        ll x = B[i].first - A[m].first;
        ll y = B[i].second - A[m].second;
        if (x < 0 && y < 0) x = 0;
        if (x * y > ret){
            ret = x*y; k = i;
        }
    }
    ret = max(ret, solve(s, m-1, l, k));
    ret = max(ret, solve(m+1, e, k, r));
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> H[i];
    for (int i=1; i<=N; i++){
        lo.push_back({i, -H[i]});
        hi.push_back({i, H[i]});
    }
    reverse(hi.begin(), hi.end());
    for (auto p : lo) if (A.empty() || A.back().second > p.second) A.push_back(p);
    for (auto p : hi) if (B.empty() || B.back().second < p.second) B.push_back(p);
    reverse(B.begin(), B.end());
    cout << solve(0, A.size()-1, 0, B.size()-1) << endl;   
}