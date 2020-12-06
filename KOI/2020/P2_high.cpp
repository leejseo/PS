#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
vector<pair<int, int>> X;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=0; i<N; i++){
        int x; cin >> x;
        if (X.empty()){
            X.push_back({x, 0});
            continue;
        }
        int y, z; tie(y, z) = X.back();
        if (x == y) continue;
        if (z == 0){
            if (x > y) X.back() = {x, 1};
            else X.back() = {x, -1};
            continue;
        }
        if (z == 1){
            if (x > y) X.back() = {x, 1};
            else X.push_back({x, -1});
            continue;
        }
        if (x < y) X.back() = {x, -1};
        else X.push_back({x, 1});
    }
    int M = X.size(); if (X[0].second == -1) M++;
    int ans = 0;
    while (M > 1){
        M = (M+1)/2;
        ans++;
    }
    cout << ans << endl;
}