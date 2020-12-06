#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int A[6], B[6];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i=0; i<6; i++){
        cin >> A[i];
    }
    for (int j=0; j<6; j++){
        cin >> B[j];
    }
    int x = 0, y = 36;
    for (int i=0; i<6; i++){
        for (int j=0; j<6; j++){
            if (A[i] > B[j]) ++x;
        }
    }
    int g = __gcd(x, y);
    x/=g;
    y/=g;
    cout << x << '/'<< y << endl;
}