#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

int N, M, K;
int H[250005], L[250005];
stack<pi> st;
bool X[250005];
vector<int> I[250005];
priority_queue<int> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> H[i] >> L[i];
    }
    for (int i=1; i<N; i++){
        if (H[i] != H[i-1] && L[i] != L[i-1]){
            X[i] = 1;
            M++;
        }
        if (H[i] != H[i-1]) K++;
        if (L[i] != L[i-1]) K++;
    }
    for (int i=1; i<N; i++){
        if (H[i-1] == H[i]){
            if (!st.empty() && st.top().first == H[i]){
                st.pop();
            }
            continue;
        }
        if (H[i-1] < H[i]){
            st.push({H[i-1], i});
            continue;
        }
        while (!st.empty() && st.top().first > H[i]) st.pop();
        if (!st.empty() && st.top().first == H[i]){
            int l = st.top().second; int r = i;
            st.pop();
            I[l].push_back(r);
            M++; 
        }
    }
    st = stack<pi>();
    for (int i=1; i<N; i++){
        if (L[i-1] == L[i]){
            if (!st.empty() && st.top().first == L[i]){
                st.pop();
            }
            continue;
        }
        if (L[i-1] < L[i]){
            st.push({L[i-1], i});
            continue;
        }
        while (!st.empty() && st.top().first > L[i]) st.pop();
        if (!st.empty() && st.top().first == L[i]){
            int l = st.top().second; int r = i;
            st.pop();
            I[l].push_back(r);
            M++; 
        }
    }
    int matching = 0;
    for (int i=1; i<=N; i++){
        while (!pq.empty() && -pq.top() < i) pq.pop();
        for (int r: I[i]) pq.push(-r);
        if (X[i]){
            if (!pq.empty()){
                pq.pop(); matching++;
            }
        }
    }
    //cout << K << ' ' << M << ' ' << matching << endl;
    cout << K - (M - matching) << endl;
}