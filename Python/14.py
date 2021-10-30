N, K = map(int,input().split())
a = [int(i) for i in input().split()]
ans = 10**20
for i in range(1 << N):
    count = 0
    base = 0
    num = 0
    for j in range(N):
        if i & (1 << j) == 0:
            base = max(base, a[j])
            continue
        else:
            count += 1
            if a[j] > base:
                base = a[j]
            else:
                num += base - a[j] + 1
                base += 1
    if count >= K:
        ans = min(ans, num)
print(ans)