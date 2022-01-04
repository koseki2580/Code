N = int(input())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]

A.sort()
B.sort()
ans = 0

for i in range(N):
    ans += abs(A[i] - B[i])
print(ans)