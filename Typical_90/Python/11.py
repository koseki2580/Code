N = int(input())
box = []
for i in range(N):
    d,c,s = map(int,input().split())
    box.append([d,c,s])
box.sort()
D = []
C = []
S = []
for i in range(N):
    D.append(box[i][0])
    C.append(box[i][1])
    S.append(box[i][2])
max_num = 5005
dp = [[0] * max_num for _ in range(max_num)]
for i in range(N):
    for j in range(max_num):
        # i番目までの仕事を使用してj日目に貰える最大の報酬額
        dp[i+1][j] = max(dp[i][j], dp[i+1][j])
        if (j + C[i]  <= D[i] ):
            dp[i+1][j + C[i]] = max(dp[i+1][j + C[i]], dp[i][j] + S[i])
ans = 0
for i in range(max_num):
    ans = max(ans,dp[N][i])
print(ans)