#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 524288;

int N, K;
ll A[250005];
ll S[250005];
priority_queue<ll> pq;
stack<ll> st;

bool trial(ll X){
    int cnt = 0;
    pq = priority_queue<ll>();
    pq.push(0);
    st = stack<ll>();
    for (int i=1; i<=N; i++){
        while (!pq.empty() && pq.top() + S[i] >= X){
            cnt++;
            st.push(pq.top()); pq.pop();
            if (cnt >= K) return true;
        }
        while (!st.empty()){
            pq.push(st.top()); st.pop();
        }
        pq.push(-S[i]);
    }
    return cnt >= K;
}

vector<ll> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1; i<=N; i++){
        S[i] = S[i-1] + A[i];
    }
    ll lo = -1E15, hi = 1E15;
    while (lo + 1 < hi){
        ll mid = lo + hi >> 1;
        if (trial(mid)) lo = mid;
        else hi = mid;
    }
    pq = priority_queue<ll>();
    pq.push(0);
    st = stack<ll>();
    for (int i=1; i<=N; i++){
        while (!pq.empty() && pq.top() + S[i] >= hi){
            ans.push_back(S[i] + pq.top());
            st.push(pq.top());
            pq.pop();
        }       
        while (!st.empty()){
            pq.push(st.top());
            st.pop();
        }
        pq.push(-S[i]);
    }
    while (ans.size() < K){
        ans.push_back(lo);
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for (auto &x: ans) cout << x << ' ';
    cout << endl;
}