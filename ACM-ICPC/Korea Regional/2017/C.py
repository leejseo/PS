import sys
raw_input = sys.stdin.readline
range = xrange
n, m = map(int, raw_input().split())
adj = [ [] for i in range(n) ]
for _ in range(m):
    u, v = map(int, raw_input().split())
    adj[u].append(v);adj[v].append(u)
order = [i for i in range(n)]
order.sort(lambda i, j : cmp(len(adj[i]), len(adj[j])))
D = [1]*n
for i in range(n):
    v = order[i]
    for u in adj[v]:
        if len(adj[u]) > len(adj[v]): D[u] = max(D[u], D[v]+1)
print max(D)
