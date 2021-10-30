N, M = map(int,input().split())
box = []
for i in range(M):
    k = list(map(int, input().split()))
    box.append(k[1:])
num = list(map(int, input().split()))

ans = 0
for i in range(1 << N):
    count = [0] * (N+1)
    for j in range(N):
        if i & (1 << j) == 0:
            continue
        else:
            for k in range(M):
                if j+1 in box[k]:
                    count[k] +=1
    flag = True
    for j in range(M):
        if count[j] %2 != num[j]:
            flag = False
            break
    if flag == True:
        ans += 1
print(ans)