from collections import deque
H, W = map(int,input().split())
box = [[-1] * (W+2) for _ in range(H+2)]
num = []
for i in range(H):
    a = list(input())
    num.append(a)

count = 0
for i in range(H):
    for j in range(W):
        if num[i][j] == '.':
            box[i+1][j+1] = 0
            count += 1


Q = deque()
Q.append([1,1,1])
box[1][1] = 1
X = [0,-1,0,1]
Y = [-1,0,1,0]
ans = 10**9+7
while len(Q) > 0:
    y,x,cost = Q.popleft()
    for i in range(4):
        yy = y + Y[i]
        xx = x + X[i]
        if yy == H and xx == W:
            ans = min(ans, cost+1)
        elif box[yy][xx] == 0:
            Q.append([yy,xx,cost+1])
            box[yy][xx] = cost
if ans == 10**9+7:
    print(-1)
else:
    print(count - ans)