import sys
raw_input = sys.stdin.readline

T = int(raw_input())
for numCase in xrange(1, T+1):
    N, P = map(int, raw_input().split())
    L = [None]*P
    for i in xrange(P):
        L[i] = raw_input().strip()
    cnt = 0
    for i in xrange(2**N):
        s = [ ('B' if j == '0' else 'R') for j in bin(i)[2:]]
        s = ''.join(s)
        t = 'B'*(N-len(s))
        s = t+s
        b = False
        for j in xrange(P):
            if s[:len(L[j])] == L[j]:
                b = True
                break
        if not b : 
            #print s
            cnt += 1
    print "Case #"+str(numCase)+":", cnt
