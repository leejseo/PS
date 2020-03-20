range = xrange
def solve(S):
    # print S
    N = len(S)

    A = [None]*(N+1)
    A[N] = 0
    A[N-1] = 1
    for i in range(N-2, -1, -1):
        A[i] = 2*A[i+1]+1

    counter = 0
    i = 0
    while True:
        while i<N and S[i]==0:
            i += 1
        if i >= N: break
        counter += A[i+1]+1  # A[N] = 0
        if i == N-1 : break
        if S[i+1] == 1 :
            i += 2
            continue
        if i + 1 == N-1 :
            counter += 1
            break
        j = i+1
        while j<N and S[j]==0:
            j += 1
            if j >= N: break        
        if j >= N :
            for x in range(i+1, N):
                counter += A[x+1] + 1
            return counter
        for x in range(i+1, j):
            counter += A[x+1] + 1
        i = j+1
    return counter
T = int(raw_input())
for case in range(T):
    L = map(int, list(raw_input()))
    print solve(L)
