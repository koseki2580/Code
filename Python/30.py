

from collections import deque
import copy
H, W, N = map(int,input().split())
INF = 10**9+7
box = [[INF] *(W+2) for _ in range(H+2)]
num = []
for i in range(H):
    a = input()
    num.append(a)
pos_ = [[] for i in range(N)]
for i in range(H):
    for j in range(W):
        if num[i][j] == ".":
            box[i+1][j+1] =-1
        elif num[i][j] == "X":
            continue
        elif num[i][j] == "S":
            box[i+1][j+1] = 0
            sy = i+1
            sx = j+1
        else:
            box[i+1][j+1] =int(num[i][j])
            pos_[int(num[i][j])-1].append([i+1,j+1])
pos = [[sy,sx]]
for i in range(N):
    pos.append([pos_[i][0][0], pos_[i][0][1]])
ans = [INF] * (N)
X = [0,-1,0,1]
Y = [-1,0,1,0]
for i in range(N):
    Q = deque()
    Q.append([pos[i][0],pos[i][1],0])
    gy = pos[i+1][0]
    gx = pos[i+1][1]
    check = copy.deepcopy(box)
    while len(Q) > 0:
        y,x,cost = Q.popleft()
        for j in range(4):
            if y + Y[j] == gy and x + X[j] == gx:
                ans[i] = min(ans[i], cost+1)
                continue
            if check[y + Y[j]][x + X[j]] != INF and ans[i] >= cost+1:
                Q.append([y + Y[j], x + X[j], cost+1])
                check[y + Y[j]][x + X[j]] = INF
print(sum(ans))