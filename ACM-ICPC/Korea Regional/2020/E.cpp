#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
int A[1000005];

void weed(){
    puts("NO");
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=0; i<N; i++){
        if (A[i] < 0) weed();
        if (A[i]){
            A[i]--;
            if (!A[i+1]) A[i+1]++;
            else A[i+1]--;
        }
    }
    for (int i=0; i<=N; i++) if (A[i]) weed();
    puts("YES");
}