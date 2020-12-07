#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, deg[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=1; i<N; i++){
        int s, e; cin >> s >> e;
        ++deg[s]; ++deg[e];
    }
    int ans = 0;
    for (int i=0; i<N; i++){
        if (deg[i] ==  1) ans++;
    }
    cout << (ans+1)/2 << endl;
}