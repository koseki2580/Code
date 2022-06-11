H, W = map(int, input().split())
box = [[0]*(W) for _ in range(H)]
for i in range(H):
    p = list(map(int, input().split()))
    for j in range(W):
        box[i][j] = p[j]

ans = 0
for i in range(1 << H):
    num = [0] * (H*W+1)
    for j in range(W):
        a = set()
        count = 0
        for k in range(H):
            if ((i >> k) & 1 == 1):
                a.add(box[k][j])
                count += 1
        if len(a) == 1:
            num[list(a)[0]] += count
    for j in num:
        ans = max(ans, j)

print(ans)
