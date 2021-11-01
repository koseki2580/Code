N, M = map(int,input().split())
a = []
for i in range(N):
    aa = [int(i) for i in input().split()]
    a.append(aa)

ans = 0
for i in range(M):
    for j in range(i+1,M):
        count = 0
        for k in range(N):
            count += max(a[k][i], a[k][j])
        ans = max(ans, count)
print(ans)