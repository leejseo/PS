#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef pair<int, int> pi;

int N;
pi A[5001];
pi p, q;
int B[5001];

inline int dist(pi a, pi b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool cmp(pi a, pi b){
    return dist(p, a) < dist(p, b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    cout << setprecision(8) << fixed;
    for (int i=0; i<N; i++) cin >> A[i].x >> A[i].y;
    int md = -1;
    for (int i=0; i<N; i++){
        for (int j=0; j<i; j++){
            int d = dist(A[i], A[j]);
            if (d > md){
                md = d;
                p = A[i], q = A[j];
            }
        }
    }
    sort(A, A+N, cmp);
    double ans = 2e9;
    for (int i=N-1; i>=0; i--){
        B[i] = B[i+1];
        for (int j=i+1; j<N; j++)
            B[i] = max(B[i], dist(A[i], A[j]));
    }
    int cur_max = 0;
    for (int i=0; i<N-1; i++){
        for (int j=0; j<i; j++){
            cur_max = max(cur_max, dist(A[i], A[j]));
        }
        ans = min(ans, sqrt(cur_max)+sqrt(B[i+1]));
    }
    cout << ans << endl;
}
