#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll C[4];
ll sx, sy, tx, ty;
ll X[500005], Y[500005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> X[i] >> Y[i];
    }
    cin >> tx >> ty;
    sx = tx + ty; sy = tx - ty;
    for (int i=1; i<=N; i++){
        tx = X[i], ty = Y[i];
        X[i] = tx + ty;
        Y[i] = tx - ty;
        if (X[i] >= sx && Y[i] >= sy) C[0]++;
        if (X[i] <= sx && Y[i] >= sy) C[1]++;
        if (X[i] >= sx && Y[i] <= sy) C[2]++;
        if (X[i] <= sx && Y[i] <= sy) C[3]++;
    }
    if (C[0] != 0 && C[1] != 0 && C[2] != 0 && C[3] != 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}