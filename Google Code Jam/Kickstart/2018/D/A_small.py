T = int(raw_input())
UNDEF = -float('inf')
for case in xrange(1, T+1):
    N, O, D = map(int, raw_input().split())
    X1, X2, A, B, C, M, L = map(int, raw_input().split())
    S = [0]*N
    S[0] = X1
    S[1] = X2
    for i in xrange(2, N):
        S[i] = (A*S[i-1] + B*S[i-2] + C)%M
    for i in xrange(N):
        S[i] += L
    ans = UNDEF
    st = 0
    ed = 0
    s = 0
    o = 0
    while ed <= N:
        if st == ed : 
            ed += 1
            if ed > N : break
            s += S[ed-1]
            o += (S[ed-1] % 2 == 1)
            continue
        if o > O or s > D:
            s -= S[st]
            o -= (S[st] % 2 == 1)
            st += 1
            continue
        ans = max(ans, s)
        if ed != N :
            ed += 1
            s += S[ed-1]
            o += (S[ed-1] % 2 == 1)            
        else:
            s -= S[st]
            o -= (S[st] % 2 == 1)            
            st += 1
    if ans == UNDEF : print 'Case #'+str(case) +':', 'IMPOSSIBLE'
    else: print 'Case #'+str(case) +':', ans
