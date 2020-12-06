#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
pair<pair<int, int>, int> A[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> A[i].first.first >> A[i].first.second;
        A[i].second = i;
    }
    sort(A+1, A+N+1);
    cout << 2*N-1 << '\n';
    for (int i=1; i<=N; i++){
        cout << A[i].second << ' ';
    }
    for (int i=N-1; i; i--) cout << A[i].second << ' ';
    cout << endl;
}