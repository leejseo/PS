n = int(raw_input())
A = map(int, raw_input().split())
a = 0
if (2*sum(A)+1) % n > 0 : a += 1
a += (2*sum(A)+1)/n
print max(a, max(A))
