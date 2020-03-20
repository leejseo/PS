#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pi;
vector<pi> A;

int T, N;
int D[101][101][101][2];
vector<int> P, E;

inline int dist(int i, int j){
    return abs(P[i] - P[j]);
}

int solve(int s, int e, int num, bool left){
    if (D[s][e][num][left] != -1) return D[s][e][num][left];
    if (num == 0){
        return D[s][e][num][left] = 0;
    }
    if (s == 0 && e == N){
        return D[s][e][num][left] = 0;
    }
    int ans = 0;
    if (s != 0){
        if (left){
            ans = max(ans, solve(s-1, e, num, true) - dist(s, s-1) * num);
            ans = max(ans, solve(s-1, e, num-1, true) - dist(s, s-1) * (num-1) + max(0, E[s-1] - dist(s, s-1)));
        }
        else {
            ans = max(ans, solve(s-1, e, num, true) - dist(e, s-1) * num);
            ans = max(ans, solve(s-1, e, num-1, true) - dist(e, s-1) * (num-1) + max(0, E[s-1] - dist(e, s-1)));
        }
    }
    if (e != N){
        if (left){
            ans = max(ans, solve(s, e+1, num, false) - dist(s, e+1) * num);
            ans = max(ans, solve(s, e+1, num-1, false) - dist(s, e+1) * (num-1) + max(0, E[e+1] - dist(s, e+1)));
        }
        else {
            ans = max(ans, solve(s, e+1, num, false) - dist(e, e+1) * num);
            ans = max(ans, solve(s, e+1, num-1, false) - dist(e, e+1) * (num-1) + max(0, E[e+1] - dist(e, e+1)));
        }
    }
    return D[s][e][num][left] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        cin >> N;
        bool z = false; int st = -1;
        A.resize(N);
        for (int i=0; i<N; i++) cin >> A[i].first;
        for (int i=0; i<N; i++) cin >> A[i].second;
        for (int i=0; i<N; i++){
            int p = A[i].first, e = A[i].second;
            if (p > 0 && !z){
                z = true;
                P.push_back(0), E.push_back(0);
                st = i;
            }
            P.push_back(p); E.push_back(e);
        }
        A.clear();
        if (!z){
            z = true;
            P.push_back(0), E.push_back(0);
            st = N;
        }
        memset(D, -1, sizeof(D));
        int ans = 0;
        for (int num=0; num<=N; num++){
            //cout << solve(st, st, num, true) << '\n';
            ans = max(ans, solve(st, st, num, true));
            ans = max(ans, solve(st, st, num, false));
        }
        cout << ans << '\n';
        P.clear();
        E.clear();
    }
}
