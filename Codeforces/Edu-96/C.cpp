#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

ll N;
vector<int> S;
vector<pair<int, int>> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        cin >> N;
        S.clear(); ans.clear();
        for (int i=1; i<=N; i++){
            S.push_back(i);
        }
        while (S.size() > 1){
            int a = S.back(); S.pop_back();
            int b = S.back();
            int c = (a+b+1)/2;
            ans.push_back({a, b});
            S[S.size() - 1] = c;
        }
        cout << S[0] << '\n';
        for (auto [x, y]: ans) cout << x << ' ' << y << '\n';
    }
}