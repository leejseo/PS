#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
int A[100005], B[100005];
int IA[100005], IB[100005];

bool vis[100005];

vector<int> P;

void trial(int u){
    P.clear();
    vis[u] = true;
    P.push_back(u);
    int al, ar;
    al = ar = IA[u];
    int bl, br;
    bl = br = IB[u];
    while (P.size() < N){
        int aal = (al + N - 1) % N;
        int bbl = (bl + N - 1) % N;
        int aar = (ar + 1) % N;
        int bbr = (br + 1) % N;
        aal = A[aal], aar = A[aar];
        bbl = B[bbl], bbr = B[bbr];
        if (aal == bbl){
            al = IA[aal], bl = IB[bbl];
            P.push_back(aal);
            vis[aal] = true;
            continue;
        }
        if (aal == bbr){
            al = IA[aal], br = IB[bbr];
            P.push_back(aal);
            vis[aal] = true;
            continue;
        }
        if (aar == bbl){
            ar = IA[aar], bl = IB[bbl];
            P.push_back(aar);
            vis[aar] = true;
            continue;
        }
        if (aar == bbr){
            ar = IA[aar], br = IB[bbr];
            P.push_back(aar);
            vis[aar] = true;
            continue;
        }
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
        --A[i];
        IA[A[i]] = i;
    }
    for (int i=0; i<N; i++){
        cin >> B[i];
        --B[i];
        IB[B[i]] = i;
    }
    for (int i=0; i<N; i++){
        if (vis[i]) continue;
        trial(i);
        if (P.size() == N){
            for (int i=0; i<N; i++) cout << P[i]+1 << ' ';
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
