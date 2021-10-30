import math
import heapq
while True:
    N = int(input())
    if N == 0:
        break
    box = []
    for i in range(N):
        x,y,z,r = map(float,input().split())
        box.append([x,y,z,r])
    root = [[] for _ in range(N)]
    for i in range(N):
        for j in range(i+1,N):
            dist = math.sqrt( (box[i][0] - box[j][0])**2 + (box[i][1] - box[j][1])**2 + (box[i][2] - box[j][2])**2 )
            dist2 = dist - box[i][3] - box[j][3]
            if  dist2 > 0:
                root[i].append([j,dist2])
                root[j].append([i,dist2])
            else:
                root[i].append([j,0])
                root[j].append([i,0])
    used = [False] * N
    ans = 0
    bb = []
    for to,cost in root[0]:
        bb.append((cost, to))
    heapq.heapify(bb)
    count = 1
    used[0] = True
    while count < N:
        cost, pos = heapq.heappop(bb)
        if used[pos] == True:
            continue
        used[pos] = True
        ans += cost
        count += 1
        for to,cost2 in root[pos]:
            if used[to] == True:
                continue
            heapq.heappush(bb, (cost2, to))
    print("{:.3f}".format(ans))