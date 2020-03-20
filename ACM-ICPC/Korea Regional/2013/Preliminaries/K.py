import sys
raw_input = sys.stdin.readline
UNDEF = int(9E18)

dist = lambda P, i, j : abs(P[j]-P[i])

def solve(P, S):
    N = len(P)
    assert P[0] == 0 and 0 <= S < N

    L = [ [UNDEF]*N  for i in xrange(N) ]
    R = [ [UNDEF]*N  for i in xrange(N) ]

    L[S][S] = R[S][S] = 0
    for l in xrange(1, N-S):
        j = S+l
        R[S][j] = R[S][j-1] + dist(P,j-1,j)*(N-l)
        L[S][j] = R[S][j] + dist(P,S,j)*(N-l)
    for l in xrange(1, S+1):
        i = S-l
        L[i][S] = L[i+1][S] + dist(P,i,i+1)*(N-l)
        R[i][S] = L[i][S] + dist(P,i,S)*(N-l)
    for l in xrange(1, N):
        for i in xrange(N-l):
            j = i+l
            L[i][j] = min(#L[i][j],
                          L[i+1][j] + dist(P, i, i+1)*(N-l) ,
                          R[i+1][j] + dist(P, j, i)*(N-l))
            R[i][j] = min(#R[i][j],
                          R[i][j-1] + dist(P, j-1, j)*(N-l),
                          L[i][j-1] + dist(P, j, i)*(N-l))
    return min(L[0][-1], R[0][-1])

T = int(raw_input())
for case in xrange(T):
    n = int(raw_input())
    s = int(raw_input())-1
    L = [0]*n
    for i in xrange(n-1):
        L[i+1] = L[i] + int(raw_input())
    print solve(L, s)
