import copy
from collections import deque


def dfs(sx, sy, gx, gy, point, box):
    if sx == gx and sy == gy and point != 0:
        return point
    count = 0
    dx = [0, -1, 0, 1]
    dy = [-1, 0, 1, 0]
    for i in range(4):
        x = sx+dx[i]
        y = sy+dy[i]
        if box[x][y] == 0:
            box[x][y] = point+1
            num = dfs(x, y, gx, gy, point+1, box)
            box[x][y] = 0
            count = max(count, num)
    return count


H, W = map(int, input().split())
box = [[-1]*(W+2) for _ in range(H+2)]
for i in range(H):
    c = input()
    for j in range(W):
        if c[j] == ".":
            box[i+1][j+1] = 0

ans = 0
for i in range(H):
    for j in range(W):
        if (box[i+1][j+1] == 0):
            box2 = copy.deepcopy(box)
            count = dfs(i+1, j+1, i+1, j+1, 0, box2)
            ans = max(ans, count)

if ans < 3:
    ans = -1
print(ans)
