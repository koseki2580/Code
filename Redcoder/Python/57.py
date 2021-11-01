import heapq
def dijkstra(start):
    b = []
    dist[start] = 0
    for to, cost in box[start]:
        b.append((cost,to))
    heapq.heapify(b)
    
    while len(b) > 0:
        cost, to = heapq.heappop(b)
        if dist[to] < cost:
            continue
        dist[to] = cost
        for to2, cost2 in box[to]:
            heapq.heappush(b,(dist[to] + cost2, to2))

n, k = map(int,input().split())
box = [[] for _ in range(n+2)]
for i in range(k):
    a = list(map(int,input().split()))
    if a[0] == 0:
        dist = [10**9]*(n+1)
        dijkstra(a[1])
        if dist[a[2]] == 10**9:
            print(-1)
        else:
            print(dist[a[2]])
    else:
        box[a[1]].append([a[2],a[3]])
        box[a[2]].append([a[1],a[3]])