from collections import deque
def bfs(now):
    Q = deque()
    Q.append([now,0])
    check[now] = True
    ans[now] = 0
    while len(Q) > 0:
        pos, cost = Q.popleft()
        for to in box[pos]:
            if check[to] == False:
                check[to] = True
                Q.append([to, cost+1])
                ans[to] = cost+1
        
    
    
N = int(input())
box = []
for i in range(N):
    a = list(map(int,input().split()))
    aa = []
    for j in range(a[1]):
        aa.append(a[2+j]-1)
    box.append(aa)

ans = [-1] * N
check = [False] * N
bfs(0)
for i in range(N):
    print(str(i+1) + " " + str(ans[i]))