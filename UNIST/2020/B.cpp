#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
string S;
vector<int> I[2];
vector<int> res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S;
    N = S.length();
    for (int i=0; i<N; i++) I[S[i]-'0'].push_back(i);
    int M = I[0].size(), K = I[1].size();
    assert(M%2 == 0); assert(K%2 == 0);
    while (I[0].size() > M/2) I[0].pop_back();
    reverse(I[1].begin(), I[1].end());
    while (I[1].size() > K/2) I[1].pop_back();
    res.resize(N); fill(res.begin(), res.end(), -1);
    for (int i: I[0]) res[i] = 0;
    for (int j: I[1]) res[j] = 1;
    for (auto x : res) if (x != -1) cout << x;
    cout << endl;
}
