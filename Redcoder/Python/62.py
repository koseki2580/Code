H, W = map(int,input().split())
box = []
for i in range(10):
    b = list(map(int,input().split()))
    box.append(b)

for k in range(10):
    for i in range(10):
        for j in range(10):
            box[i][j] = min(box[i][j], box[i][k] + box[k][j])

box2 = []
for i in range(H):
    a = list(map(int,input().split()))
    box2.append(a)
ans = 0
for i in range(H):
    for j in range(W):
        if box2[i][j] == -1:
            continue
        ans += box[box2[i][j]][1]
print(ans)