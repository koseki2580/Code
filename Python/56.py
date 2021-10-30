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
V, E, r = map(int,input().split())
box = [[] for _ in range(V)]
for i in range(E):
    s,t,d = map(int,input().split())
    box[s].append([t,d])
    #box[t].append([s,d])

dist = [10**9] * (V)
dijkstra(r)
for i in range(V):
    if dist[i] == 10**9:
        print('INF')
    else:
        print(dist[i])