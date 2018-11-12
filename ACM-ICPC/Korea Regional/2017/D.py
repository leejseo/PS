def isHappy(n):
    for i in range(1000):
        s = str(n)
        m = 0
        for i in range(len(s)):
            m += int(s[i])**2
        n = m
    return n not in [4, 16, 36, 58, 89, 145, 42, 20]

n = int(raw_input())
if isHappy(n):
    print "HAPPY"
else:
    print "UNHAPPY"
