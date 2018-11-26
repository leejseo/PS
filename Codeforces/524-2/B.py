from sys import stdin
raw_input = stdin.readline
q = int(raw_input())
for i in xrange(q):
    l, r = map(int, raw_input().split())
    p = 1
    if l%2 == 0 :
        p = -1
    s = (r - l + 1)/2
    s *= p
    if (l-r)%2 == 0 :
        s += r * ((-1)**(r%2))
    print s
