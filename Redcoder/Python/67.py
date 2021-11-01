import heapq
N = int(input())
box = []
for i in range(N):
    x,y = map(int,input().split())
    box.append([x,y,i])
dist = [[] for _ in range(N)]
box.sort()
for i in range(1,N):
    num = min(abs(box[i][0] - box[i-1][0]), abs(box[i][1] - box[i-1][1]))
    dist[box[i][2]].append([box[i-1][2],num])
    dist[box[i-1][2]].append([box[i][2],num])
box = sorted(box, key=lambda x: x[1]) 
for i in range(1,N):
    num = min(abs(box[i][0] - box[i-1][0]), abs(box[i][1] - box[i-1][1]))
    dist[box[i][2]].append([box[i-1][2],num])
    dist[box[i-1][2]].append([box[i][2],num])

used = [False] * N
count = 1
ans = 0
con = []
for to,cost in dist[0]:
    con.append((cost,to))
used[0] = True
heapq.heapify(con)
while count < N:
    cost, pos = heapq.heappop(con)
    if used[pos] == True:
        continue
    used[pos] = True
    count += 1
    ans += cost
    for to, cost2 in dist[pos]:
        if used[to] == True:
            continue
        heapq.heappush(con, (cost2,to))
print(ans)