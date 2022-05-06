N,L = map(int,input().split())
dp = [0] * (N+1)
mod = 10**9+7
dp[0] = 1
for i in range(N):
    if i + L <= N:
        dp[i+L] += dp[i]
        dp[i+L] %= mod
    dp[i+1] += dp[i]
    dp[i+1] %= mod
print(dp[N])