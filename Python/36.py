N, W = map(int,input().split())

box = []
for i in range(N):
    v,w = map(int,input().split())
    box.append([v,w])

dp = [[0] * (W+5) for _ in range(N+5)]
for i in range(N):
    for j in range(W+1):
        ww = box[i][1]
        dp[i+1][j] = max(dp[i][j], dp[i+1][j])
        if j + ww <= W:
            dp[i+1][j + ww] = max(dp[i+1][j] + box[i][0], dp[i][j + ww])
            
print(dp[N][W])