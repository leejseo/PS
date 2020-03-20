import sys
raw_input = sys.stdin.readline
T = int(raw_input())
for case in xrange(T):
    h, w, n = map(int, raw_input().split())
    col = n/h + int(n % h != 0)
    row = (n-1) % h + 1
    if col < 10 :
        print '%d0%d' %(row, col)
    else:
        print '%d%d' %(row, col)
