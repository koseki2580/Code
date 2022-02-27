N, K = map(int,input().split())
a = [int(i) for i in input().split()]
l = 0
r = 0
box = {}
ans = 0
count = 0
num = 0
while True:
    if count <=K and r == N:
        break
    if count <= K:
        num += 1
        try:
            box[a[r]] += 1
        except:
            box[a[r]] = 1
        if box[a[r]] == 1:
            count += 1
        if count <= K:
            ans = max(ans, num)
        r += 1
    else:
        num -= 1
        box[a[l]] -= 1
        if box[a[l]] == 0:
            count -= 1
        l += 1
print(ans)