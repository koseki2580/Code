from collections import deque
w, h = map(int,input().split())
box = [[-1]*(w+2) for _ in range(h+2)]
num = []
for i in range(h):
    a = list(map(int,input().split()))
    num.append(a)

for i in range(h):
    for j in range(w):
        if num[i][j] == 1:
            box[i+1][j+1] = 1
        else:
            box[i+1][j+1] = 0
check = [[False] * (w+2) for _ in range(h+2)]
ans = 0
for i in range(h):
    for j in range(w):
        if i == 2 and j == 3:
            aa = 1
        if check[i+1][j+1] == False:
            x_ = j + 1
            y_ = i + 1
            Q = deque()
            Q.append([y_, x_])
            check[y_][x_] = True
            flag = True
            base = box[y_][x_]
            count = 0
            while len(Q) > 0:
                y,x = Q.popleft()
                if y % 2 == 0:
                    X = [-1,-1,-1,0,1,0]
                    Y = [-1,0,1,-1,0,1]
                else:
                    X = [0,-1,0,1,1,1]
                    Y = [-1,0,1,-1,0,1]
                for k in range(6):
                    yy = y + Y[k]
                    xx = x + X[k]
                    if base == 1:
                        if box[yy][xx] == 1 and check[yy][xx] == False:
                            Q.append([yy,xx])
                            check[yy][xx] = True
                        elif box[yy][xx] != 1:
                            count += 1
                    else:
                        if box[yy][xx] == 1:
                            count += 1
                        elif box[yy][xx] == 0 and check[yy][xx] == False:
                            Q.append([yy,xx])
                            check[yy][xx] = True
                        elif box[yy][xx] == -1:
                            flag = False
            if flag == True and base == 1:
                ans += count
            elif flag == True and base == 0:
                ans -= count
print(ans)
