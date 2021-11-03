N, M = map(int,input().split())
num = [int(i) for i in input().split()]
box = [0] * (N+1)
for i in range(1,M):
    box[min(num[i], num[i-1])-1] += 1
    box[max(num[i], num[i-1])-1] -= 1
s = [0]
for i in range(N+1):
    s.append(s[-1] + box[i])
cost = [[0,0,0]]
for i in range(N-1):
    a,b,c  = map(int,input().split())
    cost.append([a,b,c])
ans = 0

for i in range(1,N):
    ans += min(cost[i][0] * s[i], cost[i][2] + cost[i][1] * s[i])
print(ans)