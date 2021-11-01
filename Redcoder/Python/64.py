import heapq
V, E = map(int,input().split())
box = [[] for _ in range(V)]
for i in range(E):
    a,b,c = map(int,input().split())
    box[a].append([b,c])
    box[b].append([a,c])
used = [False] * V
ans = 0
dist = []
for pos, cost in box[0]:
    dist.append((cost,pos))
heapq.heapify(dist)
used[0] = True
while len(dist) > 0:
    cost, pos = heapq.heappop(dist)
    if used[pos] == True:
        continue
    used[pos] = True
    ans += cost
    for to,cost2 in box[pos]:
        heapq.heappush(dist,(cost2, to))
print(ans)