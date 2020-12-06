#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
 
ll asum, bsum;
int N;
ll A[250001], B[250001];

vector<int> X, Y;

ll trial(){
    int n=X.size();
    ll ret=0;
    for (int i=0;i<n;i++){
        ret += abs(X[i]-Y[i]);
    }
    X.clear();
    Y.clear();
    return ret;
}
 
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1; i<=N; i++) cin >> B[i];
    if (N % 2){
        for (int i=1; i<=N; i++){
            if (A[i] < (N+1)/2) X.push_back(i);
            if (B[i] > (N+1)/2) Y.push_back(i);
        }
        ll ans = trial();
        for (int i=1; i<=N; i++){
            if (A[i] <= (N+1)/2) X.push_back(i);
            if (B[i] >= (N+1)/2) Y.push_back(i);
        }
        cout << min(ans, trial()) << endl;
    }
    else{
        for (int i=1; i<=N; i++){
            if (A[i] <= N/2) X.push_back(i);
            if (B[i] > N/2) Y.push_back(i);
        }
        cout << trial() << endl;
    }
}