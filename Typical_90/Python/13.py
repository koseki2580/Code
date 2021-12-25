import heapq

def dik(num):
    dist[num] = 0
    path = []
    for i in box[num]:
        to = i[0]
        cost = i[1]
        path.append((cost,to))
    heapq.heapify(path)
    while len(path) > 0:
        a = heapq.heappop(path)
        cost = a[0]
        pos = a[1]
        if dist[pos] < cost:
            continue
        dist[pos] = cost
        for to in box[pos]:
            if dist[to[0]] > cost + to[1]:
                heapq.heappush(path, (cost +to[1], to[0]))


N,M = map(int,input().split())
box = [[] for _ in range(N)]
for i in range(M):
    a,b,c = map(int,input().split())
    a -= 1
    b -= 1
    box[a].append([b,c])
    box[b].append([a,c])

INF = 10**9
dist = [INF] * (N)
dik(0)
dist1 = [INF] * N
for i in range(N):
    dist1[i] = dist[i]
dist = [INF] * (N)
dik(N-1)
for i in range(N):
    print(dist[i] + dist1[i])