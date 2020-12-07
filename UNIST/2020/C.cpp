#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, K;

vector<pair<int, int>> C;
queue<int> Q;

int I[300005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i=1; i<=K; i++){
        int c; cin >> c;
        C.push_back({c, i});
    }
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());
    for (int i=0; i<N; i+=2) Q.push(i);
    for (int i=1; i<N; i+=2) Q.push(i);
    if (C[0].first > (N+1)/2){
        cout << -1 << endl; return 0;
    }
    for (auto [x, y]: C){
        for (int i=0; i<x; i++){
            I[Q.front()] = y;
            Q.pop();
        }
    }
    for (int i=0; i<N; i++) cout << I[i] << ' ';
    cout << endl;
}