def dfs(now):
    ans[now].append(count[0])
    count[0] += 1
    check[now] = True

    for i in box[now]:
        if check[i] == False:
            dfs(i)
    ans[now].append(count[0])
    count[0] +=1
N =int(input())
box = [[]]
check = [False] * (N+1)
for i in range(N):
    
    a = list(map(int,input().split()))
    if a[1] == 0:
        box.append([])
        continue
    b = []
    for j in range(a[1]):
            b.append(a[2+j])
    b.sort()
    box.append(b)
ans = [[]]
for i in range(1,1+N):
    ans.append([i])
check = [False] * (N+1)

count = [1]
for i in range(1,N+1):
    if check[i] == False:
        dfs(i)
    
for i in range(1,1+N):
    print(*ans[i])