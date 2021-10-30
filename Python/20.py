def check(mid, num):
    if mid > num:
        return True
    return False
N = int(input())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
C = [int(i) for i in input().split()]

A.sort()
B.sort()
C.sort()
ans_b = []
for i in range(N):
    l = -1
    r = N
    while r -l > 1:
        mid = (l+r) // 2
        if check(B[mid], A[i]) == True:
            r = mid
        else:
            l = mid
    ans_b.append(r)

ans_c = []
for i in range(N):
    l = -1
    r = N
    while r -l > 1:
        mid = (l+r) // 2
        if check(C[mid], B[i]) == True:
            r = mid
        else:
            l = mid
    ans_c.append(N - r)
sum_c = [0]
for i in range(N):
    sum_c.append(sum_c[i] + ans_c[i])

ans = 0
for i in range(N):
    ans += (sum_c[-1] - sum_c[ans_b[i]])
    
print(ans)