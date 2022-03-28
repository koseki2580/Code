from collections import deque
H,W = map(int,input().split())
sx, sy = map(int,input().split())
gx, gy = map(int,input().split())
box = [[-1] *(W+2) for _ in range(H+2)]
flags = [[False] *(W+2) for _ in range(H+2)]
INF = 10**9
for i in range(H):
    s = input()
    for j in range(W):
        if s[j] == ".":
            box[i+1][j+1] = INF

dx = [0,-1,0,1]
dy = [-1,0,1,0]
q = deque()
# 0 1 2 3 それぞれが上の移動のむきに対応
q.append((sx,sy))
box[sx][sy] = 0
while (len(q) > 0):
    a = q.popleft()
    x = a[0]
    y = a[1]
    for i in range(4):
        xx = x + dx[i]
        yy = y + dy[i]
        cost = box[x][y] + 1
        while (box[xx][yy] >= cost ):
            box[xx][yy] = cost
            q.append((xx,yy))
            xx += dx[i]
            yy += dy[i]

print(box[gx][gy]-1)