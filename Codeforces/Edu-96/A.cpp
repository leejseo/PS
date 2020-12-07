#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T;
pair<pair<int, int>, int> D[1005];
bool able[1005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    able[0] = 1;
    for (int i=1; i<=1000; i++){
        if (i-3 >= 0 && able[i-3]){
            D[i] = D[i-3]; D[i].first.first++;
            able[i] = true;
            continue;
        }
        if (i-5 >= 0 && able[i-5]){
            D[i] = D[i-5]; D[i].first.second++;
            able[i] = true;
            continue;
        }
        if (i-7 >= 0 && able[i-7]){
            D[i] = D[i-7]; D[i].second++;
            able[i] = true;
            continue;
        }
    }
    while (T--){
        int N; cin >> N;
        if (!able[N]){
            cout << -1 << '\n'; continue;
        }
        cout << D[N].first.first << ' ';
        cout << D[N].first.second << ' ';
        cout << D[N].second;
        cout << '\n';
    }
}