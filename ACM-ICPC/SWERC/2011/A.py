from sys import stdin
from fractions import gcd
raw_input = stdin.readline
mod = 100000007
inv = lambda N : pow(N, mod-2, mod)
 
def pref(P):
    n = len(P)
    L = [0]*n
    L[0] = -1
    k = -1
    for q in range(1, n):
        while k >= 0 and P[k+1] != P[q]:
            k = L[k]
        if P[k+1] == P[q] : k = k + 1
        L[q] = k
    return L
 
def match(T, P):
    pi = pref(P)
    q = -1
    for i in range(len(T)):
        while q >= 0 and P[q+1] != T[i] :
            q = pi[q]
        if P[q+1] == T[i] : q += 1
        if q == len(P) - 1 :
            return i - len(P) + 2
    return False
 
while True:
    S, P = map(int, raw_input().split())
    if S == -1 : break
    L = [None]*P
    for i in range(P):
        L[i] = int(raw_input())
    trash = raw_input()
    L.sort()
    s = [ (L[i] - L[i-1])%360000 for i in range(P) ]
    ind = match(s[1:] + s, s)
    g = 0
    for i in range(ind):
        g += s[i]
    ans = 0
    for i in range(P/ind):
        ans += pow(S, ind * gcd(i, P/ind), mod)
        ans %= mod
    ans *= ind
    ans *= inv(P)
    ans %= mod
    print ans
