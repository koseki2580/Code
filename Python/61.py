N, M = map(int,input().split())
INF = 10**9
box = [[INF] * N for _ in range(N)]
for i in range(M):
    a,b,t = map(int,input().split())
    a -= 1
    b -= 1
    box[a][b] = t
    box[b][a] = t
for i in range(N):
    box[i][i] = 0
for k in range(N):
    for i in range(N):
        for j in range(N):
            box[i][j] = min(box[i][j], box[i][k] + box[k][j])

ans = 10**9
for i in range(N):
    ans = min(ans, max(*box[i]))
print(ans)