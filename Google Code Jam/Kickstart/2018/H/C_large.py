import sys
raw_input = sys.stdin.readline

mod = 1000000007 

F = [1]*200005
rev = [1]*200005
facrev = [1]*200005
pow2 = [1]*200005
for i in xrange(1, 200005):
    F[i] = (F[i-1]*i)%mod
    rev[i] = pow(i, mod-2, mod)
    facrev[i] = (facrev[i-1] * rev[i])%mod
    pow2[i] = (pow2[i-1]*2)%mod
    

T = int(raw_input())
for numCase in xrange(1, T+1):
    N, M = map(int, raw_input().split())
    ans = 0
    for i in xrange(M+1):
        comb = F[M]
        comb *= facrev[i]
        comb *= facrev[M-i]
        comb %= mod
        p2 = pow2[i]
        fac = F[2*N-i]
        temp = (comb * p2 * fac) % mod
        if i % 2 == 0 :
            ans += temp
            ans %= mod
        else:
            ans -= temp
            ans += mod
            ans %= mod
    print "Case #"+str(numCase)+":", ans
