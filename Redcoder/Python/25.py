from collections import deque
while True:
    w,h = map(int,input().split())
    if w == h == 0:
        break
    box = []
    for i in range(h):
        a = list(map(int,input().split()))
        box.append(a)
    ans = 0
    check = [[False] * w for _ in range(h)]
    X = [0,-1,0,1,1,1,-1,-1]
    Y = [-1,0,1,0,1,-1,1,-1]
    for i in range(h):
        for j in range(w):
            if box[i][j] == 1 and check[i][j] == False:
                ans += 1
                Q = deque()
                Q.append([i,j])
                while len(Q) > 0:
                    y_,x_  = Q.popleft()
                    for k in range(8):
                        x = x_ + X[k]
                        y = y_ + Y[k]
                        if y < 0 or y == h or x < 0 or x == w:
                            continue
                        if box[y][x] == 1 and check[y][x] == False:
                            Q.append([y,x])
                            check[y][x] = True
    print(ans)