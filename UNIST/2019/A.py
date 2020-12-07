T = int(input())

while T > 0:
    S = input()
    flag = True
    if len(S) == 7:
        if len(set(S)) == 2:
            if S[0] == S[1] == S[4] and \
               S[2] == S[3] == S[5] == S[6] :
                flag = False
    if flag:
        print(0)
    else:
        print(1)
    T -= 1