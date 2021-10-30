from collections import deque
while True:
    w, h = map(int,input().split())
    if w == 0 and h == 0:
        break
    box = [[-1] * (w*2 + 1) for _ in range(h*2 + 1)]
    for i in range(2*h - 1):
        a = list(map(int,input().split()))
        if i % 2 == 0:
            for j in range(len(a)):
                box[i+1][2+j*2] = a[j]
            for j in range(w):
                box[i+1][1+j*2] = 0
        else:
            for j in range(len(a)):
                box[i+1][1+j*2] = a[j]
    Q = deque()
    Q.append([1,1,1])
    check = [[False] * (w*2 + 1) for _ in range(h*2 + 1)]
    check[1][1] = True
    ans = 10**9+7
    X = [0,-1,0,1]
    Y = [-1,0,1,0]
    gy = 2*h-1
    gx = 2*w-1
    while len(Q) > 0:
        y,x,cost = Q.popleft()
        for i in range(4):
            yy = y + Y[i]
            xx = x + X[i]
            if (box[yy][xx] == 0) and ((yy == gy-1 and xx == gx) or (yy == gy and xx == gx-1)):
                ans = min(ans, cost + 1)
            elif check[yy][xx] == False and box[yy][xx] == 0:
                Q.append([yy+Y[i], xx+X[i], cost + 1])
                check[yy][xx]  = True
    if ans == 10**9+7:
        ans = 0
    print(ans)