#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
 
const int MAXN = 100000;
typedef pair<int, int> point;
 
vector<point> L;
int A[MAXN], P[MAXN+1], N;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    L.resize(N);
    int u, v;
    for (int i=0; i<N; i++){
        cin >> u >> v;
        L[i] = point(u, v);
    }
    sort(L.begin(), L.end());
    memset(P, -1, sizeof(P));
    for (int i=0; i<N; i++){
        u = L[i].first, v = L[i].second;
        if (P[v] != -1) A[i] = abs(P[v] - u);
        P[v] = u;
    }
    memset(P, -1, sizeof(P));
    for (int i=N-1; i>=0; i--){
        u = L[i].first, v = L[i].second;
        if (P[v] != -1){
            if (A[i] != 0) A[i] = min(A[i], abs(P[v]- u));
            else A[i] = abs(P[v] - u);
        }
        P[v] = u;
    }
    long long ans = 0;
    for (int i=0; i<N; i++) ans += (long long) A[i];
    cout << ans << endl;
}
