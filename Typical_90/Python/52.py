N = int(input())
mod = 10**9+7
A = []
for i in range(N):
    a = map(int,input().split())
    A.append(sum(a))

ans = 1
for i in range(N):
    ans *= A[i]
    ans %= mod
print(ans)