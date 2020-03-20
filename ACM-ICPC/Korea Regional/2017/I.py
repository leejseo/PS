N = int(raw_input())
A = map(int, raw_input().split())
A.append(0)

A.reverse()
ans = N
p = 1
k = 0
P = [0]*(N+1)
for i in xrange(2, N+1):
    while k != 0 and A[k+1] != A[i]: k = P[k]
    if A[k+1] == A[i] : k += 1
    P[i] = k
    if ans > N - P[i] :
        ans = N - P[i]
        p = i - P[i]
print ans-p, p
