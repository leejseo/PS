range = xrange
from sys import stdin
raw_input = stdin.readline
def solve(a, b):
    N = len(a)
    for p in range(N+1):
        if p == 0 :
            if not (b[0] < a[N-1]):
                return 0
        for l in range(1, p+1):
            if not (b[l-1] < a[N-p+l-1]):
                return p-1
            
    return N


T = int(raw_input())

for case in range(T):
    N = int(raw_input())
    a = map(float, raw_input().split())
    b = map(float, raw_input().split())
    a.sort()
    b.sort()
    v1 = solve(a, b)
    v2 = solve(b, a)
    print "Case #%d:" %(case+1) ,
    print v1, N-v2
