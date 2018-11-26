from bisect import bisect_left as lower_bound
import heapq
T = int(raw_input())
for case in xrange(1, T+1):
    pq1 = []
    pq2 = []
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
    L = [None]*N
    M = [None]*K
    for i in xrange(2, N):
        P[i] = 1+((A1 * P[i-1] + B1 * P[i-2] + C1) % M1)
        H[i] = 1+((A2 * H[i-1] + B2 * H[i-2] + C2) % M2)
    for i in xrange(2, K):
        X[i] = 1+((A3 * X[i-1] + B3 * X[i-2] + C3) % M3)
        Y[i] = 1+((A4 * Y[i-1] + B4 * Y[i-2] + C4) % M4)  
    for i in xrange(N):
        L[i] = (P[i], H[i])
    for i in xrange(K):
        M[i] = (X[i], Y[i])
    L.sort()
    M.sort()
    able = [0]*K
    #left tower
    prev = -1
    for i in xrange(K):
        while prev < N-1:
            if L[prev+1][0] <= M[i][0]:
                prev += 1
                heapq.heappush(pq1, -L[prev][0]-L[prev][1])
                continue
            break
        if pq1:
            v = pq1[0]
            if M[i][0] + M[i][1] <= -v :
                able[i] = 1
    prev = N
    for i in xrange(K-1, -1, -1):
        while prev > 0:
            if L[prev-1][0] >= M[i][0]:
                prev -= 1
                heapq.heappush(pq2, L[prev][0]-L[prev][1])
                continue
            break
        if pq2:
            v = pq2[0]
            if M[i][1] - M[i][0] <= -v:
                able[i] = 1
    print 'Case #'+str(case)+':',sum(able)
        
        
