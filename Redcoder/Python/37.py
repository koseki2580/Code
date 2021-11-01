n, m = map(int,input().split())
c = [int(i) for i in input().split()]
dp = [10**9+7] * (n+1)
dp[0] = 0
for i in range(n):
    for j in range(m):
        if i + c[j] <= n:
            dp[i + c[j]] = min(dp[i] + 1, dp[i + c[j]])
print(dp[n])