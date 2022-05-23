N, S = map(int, input().split())
A = []
B = []
for i in range(N):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

dp = [[""] * (10**5+5) for _ in range(105)]
dp[0][A[0]] = "A"
dp[0][B[0]] = "B"

for i in range(1, N):
    for j in range(10**5+1):
        if len(dp[i-1][j]) == 0:
            continue
        if j + A[i] <= S:
            dp[i][j+A[i]] = dp[i-1][j] + "A"
        if j + B[i] <= S:
            dp[i][j+B[i]] = dp[i-1][j] + "B"

ans = "Impossible"
if len(dp[N-1][S]) != 0:
    ans = dp[N-1][S]
print(ans)
