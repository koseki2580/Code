K = int(input())
mod = 10**9+7
if K % 9 != 0:
    print(0)
    exit(0)
dp = [0] * (K+1)
for i in range(1,10):
    dp[i] = 1
for i in range(1,K+1):
    for j in range(1,10):
        if i+j > K:
            break
        dp[i+j] += dp[i]
        dp[i+j] %= mod
print(dp[K])