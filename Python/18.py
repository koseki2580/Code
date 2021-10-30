def check(mid, num):
    if S[mid] <= num:
        return True
    return False

N = int(input())
S = [int(i) for i in input().split()]
q = int(input())
T = [int(i) for i in input().split()]
ans = 0
for i in range(q):
    l = 0
    r = len(S)
    while r -l > 1:
        mid = (r+l) //2
        if check(mid, T[i]) == True:
            l = mid
        else:
            r = mid
            
    if S[l] == T[i]:
        ans += 1
print(ans)