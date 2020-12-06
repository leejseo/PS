#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
ll H[300005];

const ll INVAL = 1E9;

bool trial(ll x){
    int st = INVAL;
    for (int i=1; i<=N; i++){
        if (H[i] < x){
            st = INVAL;
            continue;
        }
        if (st == INVAL) st = i;
        if (i - st + 1 >= x) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> H[i];
    ll lo = 1, hi = N+1;
    while (lo + 1 < hi){
        ll mid = (lo + hi)/2;
        if (trial(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << endl;
}