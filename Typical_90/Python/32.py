import itertools
N = int(input())
INF = 10**9
A = []
for i in range(N):
    b = list(map(int,input().split()))
    A.append(b)
M = int(input())
box = [[0]*N for _ in range(N)]
for i in range(M):
    x,y = map(int,input().split())
    x -= 1
    y -= 1
    box[x][y] = -1
    box[y][x] = -1
ans = INF
con = list(itertools.permutations(range(N), N))
for i in range(len(con)):
    flag = False
    for j in range(N-1):
        if (box[con[i][j]][con[i][j+1]] == -1):
            flag = True
            break
    if flag == True:
        continue
    count = 0
    for j in range(N):
        count += A[con[i][j]][j]
    ans = min(ans,count)

if ans == INF:
    ans = -1
print(ans)