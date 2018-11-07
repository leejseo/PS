#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long lld;
typedef struct Point{
	int x, y, w;
	Point(){ x = 0, y = 0, w = 0; }
} Point;

typedef struct Vert{
	int x, w;
	Vert(){ x = 0, w = 0; }
	Vert(int x_, int w_){ x = x_, w = w_; }
} Vert;

typedef struct Node{
	lld s, m, l, r;
	Node(){ s = 0, m = 0, l = 0, r = 0; }
} Node;

typedef struct SegmentTree{
	vector<Node> tree;
	SegmentTree(){}
	void init(int Size){
		tree.clear();
		int p = 1;
		while (p < Size) p *= 2;
		tree.resize(p*2);
	}
	void update(int i, int v){
		int node = (tree.size() >> 1) + i - 1;
		tree[node].s += v;
		tree[node].m = max(tree[node].s, 0LL);
		tree[node].l = tree[node].m;
		tree[node].r = tree[node].m;
		node = node >> 1;
		while (node){
			int left = 2 * node;
			int right = 2 * node + 1;
			tree[node].s += v;
			tree[node].l = max(tree[left].l, tree[left].s + tree[right].l);
			tree[node].r = max(tree[right].r, tree[right].s + tree[left].r);
			tree[node].m = max(tree[left].r + tree[right].l, max(tree[left].m, tree[right].m));
			node = node >> 1;
		}
	}
	lld getMax() { return tree[1].m; }
} SegmentTree;

int N;
vector<int> X, Y;
int NX, NY;
vector<Point> P;
vector<Vert> Line[3000];

inline int getX(int x) { return lower_bound(X.begin(), X.end(), x) - X.begin(); }
inline int getY(int y) { return lower_bound(Y.begin(), Y.end(), y) - Y.begin(); }

int W[3000][3000];

void input(){
	cin >> N;
	P.resize(N);
	for (int i=0; i<N; i++){
		cin >> P[i].x >> P[i].y >> P[i].w;
		X.push_back(P[i].x);
		Y.push_back(P[i].y);
	}
	sort(X.begin(), X.end()); unique(X.begin(), X.end());
	sort(Y.begin(), Y.end()); unique(Y.begin(), Y.end());
	NX = X.size(); NY = Y.size();
	for (int i=0; i<N; i++) W[getY(P[i].y)][getX(P[i].x)] = P[i].w;
	for (int i=0; i<NY; i++){
		for (int j=0; j<NX; j++){
			if (W[i][j] != 0) Line[i].push_back(Vert(j, W[i][j]));
		}
	}
}

lld solve(){
	lld ans = -1;
	SegmentTree T;
	for (int i=0; i<NY; i++){
		T.init(NX);
		for (int j=i; j<NY; j++){
			for (int k=0; k<Line[j].size(); k++){
				int idx = Line[j][k].x + 1;
				int v = Line[j][k].w;
				T.update(idx, v);
			}
			ans = max(ans, T.getMax());
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);
	input();
	cout << solve() << endl;
}
