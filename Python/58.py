from collections import deque
import heapq
"""
遅かった原因は
BFSでQからpopleft()する際に2つの変数、to, costを取り出すとめちゃめちゃ遅くなるっぽい
だからdist配列を別で作成して1つだけをpopさせる形をとる
また、ダイクストラ法もforループ内でdistの書き換えを行うことで高速化する

"""
def bfs(start):
    Q = deque()
    Q.append(start)
    dist[start] = 0
    while len(Q) > 0:
        pos = Q.popleft()
        if dist[pos] > S:
            continue
        for to in box[pos]:
            if dist[to] == -1:
                dist[to] = dist[pos] + 1
                inn[to] = q
                Q.append(to)
def dijkstra():
    Q = [(0,0)]
    dist[0] = 0
    while Q:
        cost, pos = heapq.heappop(Q)
        if pos == N-1:
            break
        for to in box[pos]:
            if cost + inn[to] < dist[to]:
                # ここで値を変更しておく必要がある、そうしないと無駄なループが増えてしまう
                dist[to] = cost + inn[to]
                heapq.heappush(Q,(dist[to], to))
                
N, M , K, S = map(int,input().split())
p, q = map(int,input().split())
zonbi  = []
for i in range(K):
    k = int(input())
    k -= 1
    zonbi.append(k)
box = [[] for _ in range(N+1)]
for i in range(M):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    box[a].append(b)
    box[b].append(a)
for i in zonbi:
    box[-1].append(i)
dist = [-1] *(N+1)
inn = [p] * (N)
bfs(N)
INF = 10**100
for i in box[-1]:
    inn[i] = INF
inn[-1] = 0
dist = [INF] * N
dijkstra()
print(dist[N-1])
