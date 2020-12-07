from collections import deque
from sys import stdin
input = stdin.readline
N = int(input())
D = {"Baba" : 0}
num = 1
A = [None]*200005
ans = []
V = [False]*200005
A[0] = "Baba"
adj = [ [] for i in range(200005)]
for i in range(N):
    a, b, c, = input().strip().split()
    if a not in D:
        D[a] = num
        A[num] = a
        num += 1
    if c not in D:
        D[c] = num
        A[num] = c
        num += 1
    adj[D[a]].append(D[c])

Q = deque()
Q.append(0)
while len(Q) != 0:
    p = Q.popleft()
    V[p] = True
    for x in adj[p]:
        if not V[x]:
            Q.append(x)
for i in range(1, 200005):
    if V[i] : ans.append(A[i])
ans.sort()
for s in ans:
    print(s)