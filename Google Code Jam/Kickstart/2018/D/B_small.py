T = int(raw_input())
for case in xrange(1, T+1):
    N, K = map(int, raw_input().split())
    p1, p2, A1, B1, C1, M1 = map(int, raw_input().split())
    h1, h2, A2, B2, C2, M2 = map(int, raw_input().split())
    x1, x2, A3, B3, C3, M3 = map(int, raw_input().split())
    y1, y2, A4, B4, C4, M4 = map(int, raw_input().split())
    P = [0]*N
    H = [0]*N
    X = [0]*K
    Y = [0]*K
    P[0], P[1] = p1, p2
    H[0], H[1] = h1, h2
    X[0], X[1] = x1, x2
    Y[0], Y[1] = y1, y2
    for i in xrange(2, N):
        P[i] = 1+((A1 * P[i-1] + B1 * P[i-2] + C1) % M1)
        H[i] = 1+((A2 * H[i-1] + B2 * H[i-2] + C2) % M2)
    for i in xrange(2, K):
        X[i] = 1+((A3 * X[i-1] + B3 * X[i-2] + C3) % M3)
        Y[i] = 1+((A4 * Y[i-1] + B4 * Y[i-2] + C4) % M4)  
    cnt = 0
    for i in xrange(K):
        meet = False
        for j in xrange(N):
            if Y[i] + abs(X[i] - P[j]) <= H[j] :
                meet = True
                break
        if meet : cnt += 1
    print "Case #"+str(case)+':', cnt
