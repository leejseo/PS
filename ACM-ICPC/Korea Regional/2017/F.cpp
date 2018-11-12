n, m = map(int, raw_input().split())
def sana(n, m, X, Y, x, y, z, w):
    if not (1 <= m <= n*n) : return    
    if n == 1: print X, Y; return
    N = n/2
    M = N*N
    sana(N, m-0*M, X+(x%2)*N, Y+(x/2)*N, x, w, z, y)
    sana(N, m-1*M, X+(y%2)*N, Y+(y/2)*N, x, y, z, w)
    sana(N, m-2*M, X+(z%2)*N, Y+(z/2)*N, x, y, z, w)
    sana(N, m-3*M, X+(w%2)*N, Y+(w/2)*N, z, y, x, w)
    return
sana(n, m, 1, 1, 0, 2, 3, 1)
