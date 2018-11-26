import sys
raw_input = sys.stdin.readline

mod = 1000000007 

C = [ [0]*300 for i in xrange(300) ]

for i in xrange(1, 300):
    C[i][0], C[0][i] = 1, 1
C[1][1] = 1
for i in xrange(2, 300):
    for j in xrange(1, i+1):
        C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod

F = [1]*500
for i in xrange(1, 500):
    F[i] = F[i-1]*i

T = int(raw_input())
for numCase in xrange(1, T+1):
    N, M = map(int, raw_input().split())
    ans = 0
    for i in xrange(M+1):
        temp = (C[M][i] * pow(2, i, mod) * F[2*N-i])%mod
        if i % 2 == 0 :
            ans += temp
            ans %= mod
        else:
            ans -= temp
            ans += mod
            ans %= mod
    print "Case #"+str(numCase)+":", ans
