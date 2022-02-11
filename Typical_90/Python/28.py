N = int(input())
a = 1002
box = [[0] * (a) for _ in range(a)]
for i in range(N):
    lx,ly,rx,ry = map(int,input().split())
    box[lx][ly] += 1
    box[rx][ry] += 1
    box[lx][ry] -= 1
    box[rx][ly] -= 1

for i in range(a):
    for j in range(1, a):
        box[i][j] += box[i][j-1]
for i in range(a):
    for j in range(1, a):
        box[j][i] += box[j-1][i]

ans = [0] * N
for i in range(a):
    for j in range(a):
        if box[i][j] != 0:
            ans[box[i][j]-1] += 1
for i in range(N):
    print(ans[i])