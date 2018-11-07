#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
const int MAXN = 200001;
 
struct DP{
    // Note that all numbers are different
    // Data structure for 2D LIS Query
    set<pii> S[MAXN+1];
    DP(){}
    void update(int i, pii &p){
        //Amortized O(log N)
        //Each pii is inserted at most once and deleted at most once
        S[i].insert(p);
        set<pii>::iterator it;
        it = S[i].lower_bound(p);
        if (it != S[i].begin()){
            --it;
            if ((*it).second < p.second){
                ++it;
                S[i].erase(it);
                return;
            }
        }
        while(1){
            it = S[i].lower_bound(p);
            ++it;
            if (it == S[i].end()) break;
            if ((*it).second < p.second) break;
            else S[i].erase(it);
        }
    }
 
    bool check(int i, pii&p){
        set<pii>::iterator it;
        it = S[i].lower_bound(p);
        if (it == S[i].begin()) return 0;
        --it;
        return ((*it).second < p.second);
    }
} D;
 
vector<pii> L;
 
int solve(){
    int N = L.size();
    int ans = 0;
    for (int i=0; i<N; i++){
        int lo = 0, hi = N-1;
        while (lo < hi){
            int mid = (lo + hi)/2 + 1;
            if (D.check(mid, L[i])) lo = mid;
            else hi = mid-1;
        }
        D.update(lo+1, L[i]);
        ans = max(ans, lo+1);
    }
    return ans;
}
 
typedef pair<int, pii> tri;
vector<tri> V;
 
void init(){
    int M, N;
    cin >> M >> N;
    V.resize(N);
    L.resize(N);
    if (M == 2){
        for (int i=0; i<N; i++) cin >> V[i].first;
        for (int i=0; i<N; i++) cin >> V[i].second.first;
        sort(V.begin(), V.end());
        for (int i=0; i<N; i++) L[i] = pii(V[i].second.first, i);
    }
    else{
        for (int i=0; i<N; i++) cin >> V[i].first;
        for (int i=0; i<N; i++) cin >> V[i].second.first;
        for (int i=0; i<N; i++) cin >> V[i].second.second;
        sort(V.begin(), V.end());
        for (int i=0; i<N; i++) L[i] = V[i].second;
    }
    V.clear();
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    init();
    cout << solve() << '\n';
}
