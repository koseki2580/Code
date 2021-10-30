import heapq
N, M, K = map(int,input().split())
box = [[] for _ in range(N)]
for i in range(M):
    a,b,c  = map(int,input().split())
    a -= 1
    b -= 1
    box[a].append([b,c])
    box[b].append([a,c])



used = [False] * N
ans = 0
dist = []
for pos, cost in box[0]:
    dist.append((cost,pos))
marked = 1
heapq.heapify(dist)
used[0] = True
cost_box = []
while marked < N:
    cost, pos = heapq.heappop(dist)
    if used[pos] == True:
        continue
    marked += 1
    used[pos] = True
    heapq.heappush(cost_box,-cost)
    ans += cost
    for to,cost2 in box[pos]:
        if used[to] == True:
            continue
        heapq.heappush(dist,(cost2, to))
        
        
for i in range(1,K):
    ans += heapq.heappop(cost_box)
print(ans)