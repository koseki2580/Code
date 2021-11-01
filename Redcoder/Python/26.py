import sys
sys.setrecursionlimit(10**6)

def dfs(now , parent = -1):
    ans[now] = cost[now] + cost[parent]
    cost[now] += cost[parent]
    for i in box[now]:
        if parent != i and ans[i] == 0:
            dfs(i, now)

N, Q = map(int,input().split())
box = [[] for _ in range(N*1)]
for i in range(N-1):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    box[a].append(b)
    box[b].append(a)

cost = [0] * (N+1)
for i in range(Q):
    p,x = map(int,input().split())
    p -= 1
    cost[p] += x

ans = [0]*(N)
dfs(0)
print(*ans)