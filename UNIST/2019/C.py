import sys
input = sys.stdin.readline

Q, M = map(int, input().split())
A = [0, 1, 1]
while A[-2] != 0 or A[-1] != 1:
    A.append((A[-1]+A[-2])%M)
A.pop()
A.pop()
S = ""
for i in A :
    S += str(i)

for _ in range(Q):
    n = int(input())
    print(S[n%len(S)])