def check(num):
    count = 0
    before = 0
    for i in range(N):
        if A[i] - before >= num:
            before = A[i]
            count += 1
        if count == K:
            if L - before >= num:
                return True
            return False
    return False

N,L = map(int,input().split())
K = int(input())
A = [int(i) for i in input().split()]
A.append(L)
l = 0
r = 10**10

while (r-l) > 1:
    mid = (r+l)//2
    if check(mid) == True:
        l = mid
    else:
        r = mid

print(l)