N, M = map(int,input().split())
box = [[False] *(14) for _ in range(14)]
for i in range(14):
    box[i][i] = True
ans = 0
for i in range(M):
    x,y = map(int,input().split())
    x -= 1
    y -= 1
    box[x][y] = True
    box[y][x] = True

for i in range(1 << N):

    ok = True
    box2 = []
    for j in range(N):
        if i & (1 << j) == 0:
            continue
        else:
            box2.append(j)
    for j in range(len(box2)):
        for k in range(len(box2)):
            if box[box2[j]][box2[k]] == False:
                ok = False
                break
        if ok == False:
            break
    if ok == True:
        ans = max(ans,len(box2))
print(ans)