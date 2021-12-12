N = int(input())
S = input()
s = {"a":1, "t":2, "c":3, "o":4, "d":5, "e":6, "r":7}
mod = 10**9+7
dp = [[0] * 8 for _ in range(N+1)]
for i in range(N):
    dp[i][0] = 1
for i in range(1,1+N):
    mozi = S[i-1]
    for j in range(8):
        dp[i][j] = dp[i-1][j]
    try:
        num = s[mozi]
        dp[i][num] = dp[i-1][num] + dp[i-1][num-1]
        dp[i][num] %= mod
    except:
        continue
print(dp[N][-1] % mod)