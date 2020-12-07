import sys
input = sys.stdin.readline
K, N, M = map(int, input().split())
X = [ set() for _ in range(K+1) ]
move = [None] * (N-1)
for i in range(N-1):
    t, a, b = map(int, input().split())
    move[i] = (t, a, b)
ans = [-1] * M
Q = [ [] for _ in range(N) ]
for i in range(M):
    s, m, t, a, b = map(int, input().split())
    Q[m-1].append((i, t, a, b))
    X[s].add(i)

for i in range(N):
    for idx, t, a, b in Q[i]:
        if t == 1:
            if idx in X[a]:
                X[a].remove(idx)
                X[b].add(idx)
            elif idx in X[b]:
                X[b].remove(idx)
                X[a].add(idx)
        else:
            if idx in X[a]:
                X[a].remove(idx)
                X[b].add(idx)
    if i == N-1: break
    t, a, b = move[i]
    if t == 1:
        X[a], X[b] = X[b], X[a]
    elif len(X[a]) <= len(X[b]):
        X[b] |= X[a]
        X[a] = set()
    else:
        X[a] |= X[b]
        X[b] = set()
        X[a], X[b] = X[b], X[a]

for i in range(K+1):
    for x in X[i]: ans[x] = i

for x in ans: print(x)