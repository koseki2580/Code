from collections import deque

def DFS(num):
    Q = deque()
    Q.append(num)
    dist[num] = 0
    while len(Q) > 0:
        pos = Q.popleft()
        for to in box[pos]:
            if dist[to] == -1:
                dist[to] = dist[pos] + 1
                Q.append(to)

N = int(input())
box = [[] for _ in range(N)]
for i in range(N-1):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    box[a].append(b)
    box[b].append(a)

dist = [-1] * (N)
DFS(0)

next = 0
a = 0
for i in range(N):
    if a < dist[i]:
        next = i
        a = dist[i]
        
dist = [-1] * (N)
DFS(next)
ans = 0
for i in range(N):
    ans = max(ans,dist[i])
ans += 1
print(ans)