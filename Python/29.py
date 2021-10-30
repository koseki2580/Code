from collections import deque
R, C = map(int,input().split())
sy, sx = map(int,input().split())
gy, gx = map(int,input().split())
box = [[-1]*(C+2) for _ in range(R+2)]
num = []
for i in range(R):
    a = input()
    num.append(a)
for i in range(R):
    for j in range(C):
        if num[i][j] == ".":
            box[i+1][j+1] = 0

Q = deque()
Q.append([sy,sx, 0]) 
box[sy][sx] = 1
X = [0,-1,0,1]
Y = [-1,0,1,0]
ans = 10**9+7
while len(Q) > 0:
    y,x,cost = Q.popleft()
    for i in range(4):
        if y + Y[i] == gy and x + X[i] == gx :
            ans = min(ans,cost+1)
            continue
        if box[y + Y[i]][x + X[i]] == 0:
            Q.append([y + Y[i], x + X[i], cost+1])
            box[y + Y[i]][x + X[i]] = cost+1
print(ans)