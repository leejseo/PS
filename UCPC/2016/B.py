import sys
sys.setrecursionlimit(1000000)
def power(x):
    if x == 0 or x == 1 : return 0
    i = 1
    c = 2
    while c < x :
        i += 1
        c *= 2
    return c

class SegmentTree(object):
    def __init__(self, arr):
        n = len(arr)
        c = power(n)        
        self.arr = arr + [0]*(c - n)
        self.tree = [0]*(2*c)
        self.lazy = [0]*(2*c)
    
    def set_tree(self, node, begin, end):
        if begin == end:
            self.tree[node] = self.arr[begin]
            return self.tree[node]
        mid = (begin + end)/2
        self.tree[node] = self.set_tree(2*node, begin, mid) \
            + self.set_tree(node*2 +1, mid+1, end)
        return self.tree[node]
    
    def update_lazy(self, node, begin, end):
        if self.lazy[node] != 0 :
            self.tree[node] += (end - begin + 1)*self.lazy[node]
            if begin != end :
                self.lazy[node*2] += self.lazy[node]
                self.lazy[node*2 + 1] += self.lazy[node]
        self.lazy[node] = 0
    
    def get_sum(self, node, begin, end, left, right):
        self.update_lazy(node, begin, end)
        if end < left or right < begin: return 0
        if left <= begin and end <= right : return self.tree[node]
        mid = (begin + end)/2
        return self.get_sum(node*2, begin, mid, left, right) + \
               self.get_sum(node*2 + 1, mid+1, end, left, right)
    
    def update(self, node, begin, end, left, right, diff):
        self.update_lazy(node, begin, end)
        if end < left or right < begin: return
        if left <= begin and end <= right:
            self.tree[node] += (end - begin + 1)*diff
            if begin != end :
                self.lazy[node * 2] += diff
                self.lazy[node * 2 + 1] += diff
            return
        mid = (begin + end)/2
        self.update(node*2, begin, mid, left, right, diff)
        self.update(node*2 + 1, mid+1, end, left, right, diff)
        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]
raw_input = sys.stdin.readline
range = xrange
N = int(raw_input())
S = [-1]*N
E = [-1]*N
V = []
for i in range(N):
    S[i], E[i] = map(int, raw_input().split())
    V.append(S[i])
    V.append(E[i])
V = list(set(V))
V.sort()
M = len(V)
F = dict()
for i in range(M):
    F[V[i]] = i
seg = SegmentTree([0]*M)
for i in range(N):
    seg.update(1, 0, N-1, F[S[i]], F[E[i]], 1)
W = 0
ind = -1
for i in range(M):
    val = seg.get_sum(1, 0, N-1, i, i)
    if val > W :
        W = val
        ind = i
print W
for i in range(N):
    if S[i] <= V[ind] <= E[i]:
        print i+1,
print
