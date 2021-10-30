import heapq
from collections import deque

N, K = map(int,input().split())
C = []
R = []
for i in range(N):
    c,r = map(int,input().split())
    C.append(c)
    R.append(r)

box2 = [[] for _ in range(N)]
for i in range(K):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    box2[a].append(b)
    box2[b].append(a)
    
box = [[] for _ in range(N)]
for i in range(N):
    dist = [10**9] * N
    Q = deque()
    Q.append(i)
    dist[i] = 0
    while Q:
        pos = Q.popleft()
        if dist[pos]  >= R[i]:
            continue
        for to in box2[pos]:
            if dist[to] == 10**9:
                dist[to] = dist[pos] + 1
                Q.append(to)
                box[i].append(to)

dist = [10**9] * N
Q = [(0,0)]
dist[0] = 0
#heapq.heapify(b)
while Q:
    cost, pos = heapq.heappop(Q)

    if pos == N-1:
        break
    for to in box[pos]:
        if cost + C[pos] < dist[to]:
            dist[to] = dist[pos] + C[pos]
            heapq.heappush(Q,(dist[to], to))
print(dist[-1])

def dijkstra():
    Q = [(0,0)]
    dist[0] = 0
    while Q:
        cost, pos = heapq.heappop(Q)
        if pos == N-1:
            break
        for to in box[pos]:
            if cost + C[pos] < dist[to]:
                # ここで値を変更しておく必要がある、そうしないと無駄なループが増えてしまう
                dist[to] = dist[pos] + C[pos]
                heapq.heappush(Q,(dist[to], to))