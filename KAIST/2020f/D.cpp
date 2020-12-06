#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;
ll C[10500];
ll ans1, ans2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    M = N*(N-1)/2;
    for (int i=0; i<M; i++) cin >> C[i];
    sort(C, C+M);
    for (int i=0; i<N-1; i++){
        ans1 += C[i];
    }
    reverse(C, C+M);
    int cur = 0;
    for (int i=N-1; i>0; i--){
        cur += i;
        ans2 += C[cur-1];
    }
    cout << ans1 << ' ' << ans2 << endl;
}