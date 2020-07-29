#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
int M;
vector<pair<int, int>> E;

void add(int u, int v){
    cout << u << ' ' << v << '\n';
}

const int K = 8;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    if (N % K == 6 % K){
        M = 6;
        add(1, 3);
        add(2, 3);
        add(3, 4);
        add(4, 5);
        add(5, 6);
    }
    else if (N % K == 7 % K){
        M = 7;
        add(1, 3);
        add(2, 3);
        add(3, 5);
        add(4, 5);
        add(5, 6);
        add(6, 7);
    }
    else if (N % K == 8 % K){
        M = 8;
        add(1, 3);
        add(2, 3);
        add(3, 4);
        add(4, 5);
        add(5, 6);
        add(5, 7);
        add(7, 8);
    }
    else if (N % K == 9 % K){
        M = 9;
        add(1, 2);
        add(2, 3);
        add(4, 5);
        add(5, 3);
        add(8, 3);
        add(9, 8);
        add(6, 3);
        add(7, 6);
    }
    else if (N % K == 10 % K){
        M = 10;
        add(1, 2);
        add(2, 6);
        add(2, 7);
        add(1, 3);
        add(3, 8);
        add(1, 4);
        add(4, 5);
        add(1, 9);
        add(9, 10);
    }
    else if (N % K == 11 % K){
        M = 11;
        add(1, 2);
        add(2, 3);
        add(3, 4);
        add(2, 5);
        add(5, 6);
        add(2, 7);
        add(7, 8);
        add(8, 9);
        add(9, 10);
        add(10, 11);
    }
    else if (N % K == 12 % K){
        M = 12;
        add(1, 2);
        add(2, 6);
        add(2, 7);
        add(1, 3);
        add(3, 8);
        add(3, 9);
        add(1, 4);
        add(4, 10);
        add(4, 5);
        add(1, 11);
        add(11, 12);
    }
    else if (N % K == 13 % K){
        M = 13;
        add(1, 3);
        add(2, 3);
        add(3, 4);
        add(4, 5);
        add(5, 6);
        add(6, 7);
        add(7, 8);
        add(3, 9);
        add(9, 10);
        add(10, 11);
        add(11, 12);
        add(12, 13);
    }
    while (M < N){
        add(M, M+1);
        add(M+1, M+3);
        add(M+2, M+3);
        add(M+3, M+4);
        add(M+4, M+5);
        add(M+3, M+6);
        add(M+6, M+7);
        add(M+7, M+8);
        M += 8;
    }
}
