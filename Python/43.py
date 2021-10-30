N = int(input())
box = [[] for _ in range(N)]
for i in range(5):
    a = input()
    for j in range(N):
        box[j].append(a[j])
        
dp = [[10**9+7] *(3) for _ in range(N+1)]
dp[0][0] = 0
dp[0][1] = 0
dp[0][2] = 0
check = ["R", "B", "W"]
for i in range(N):
    for j in range(3):
        count = 0
        for k in range(5):
            if check[j] == box[i][k]:
                count += 1
        dp[i+1][j] = min(dp[i][j-1] +(5-count),  dp[i][j-2] + (5-count))
print(min(dp[N]))