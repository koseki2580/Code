from collections import deque
def bfs():
    q = deque()
    q.append(0)
    dist[0] = 0
    while len(q) > 0:
        pos = q.popleft()
        for to in box[pos]:
            if dist[to] == -1:
                dist[to] = (dist[pos] + 1) % 2
                q.append(to)
N = int(input())
box = [[] for _ in range(N)]
for i in range(N-1):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    box[a].append(b)
    box[b].append(a)

dist = [-1] * N 
bfs()

# めちゃめちゃまどろっこしい方法で回答
ans_0 = []
ans_1 = []

for i in range(N):
    if dist[i] == 0:
        ans_0.append(i+1)
    else:
        ans_1.append(i+1)
ans = []
if len(ans_0) > N//2:
    for i in range(N//2):
        ans.append(ans_0[i])
else:
    for i in range(N//2):
        ans.append(ans_1[i])
print(*ans)