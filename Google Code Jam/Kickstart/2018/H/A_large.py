import sys
raw_input = sys.stdin.readline

T = int(raw_input())
for numCase in xrange(1, T+1):
    N, P = map(int, raw_input().split())
    S = [None]*P
    for i in xrange(P):
        S[i] = raw_input().strip()
    ans = 2**N
    for i in xrange(P):
        ans -= 2**(N - len(S[i]))
    for i in xrange(P):
        for j in xrange(P):
            if j == i :
                continue
            if len(S[i]) <= len(S[j]):
                continue
            if S[i][:len(S[j])] == S[j]:
                ans += 2**(N - len(S[i]))
                break
    print "Case #"+str(numCase)+":", ans
