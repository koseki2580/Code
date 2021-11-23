N = int(input())
A = [int(i) for i in input().split()]
mod = 1000000007
box = [0] * (N+1)
ans = 1
box[-1] = 3
for i in range(N):
    ans *= box[A[i]-1] -box[A[i]]
    ans %= mod
    box[A[i]] += 1
print(ans)