S = list(input())
A = []
for s in S :
    if s != " ":
        A.append(s)

EXP = ["+", "-", "/", "*", "%"]

def solve(S):
    if len(S) == 1 and S[0].isalpha(): return True
    n = len(S)
    for i in range(n-2):
        if S[i].isalpha() and S[i+1] in EXP and S[i+2].isalpha():
            return solve(S[:i]+["a"]+S[i+3:])
        if S[i] == "(" and S[i+1].isalpha() and S[i+2] == ")":
            return solve(S[:i]+["a"]+S[i+3:])
    return False

def check(S):
    return check_rec(S) or (len(S) == 1 and  S[0].isalpha()) 

def check_rec(S):
    if len(S) == 3 and S[0].isalpha() and S[1] in EXP and S[2].isalpha():
        return True
    n = len(S)
    for i in range(n-4):
        if S[i]=="(" and S[i+1].isalpha() and S[i+2] in EXP \
           and S[i+3].isalpha() and S[i+4]==")":
            return check_rec(S[:i] + ["a"] + S[i+5:])
    return False

if solve(A):
    if check(A):
        print ("proper")
    else:
        print ("improper")
else:
    print ("error")
