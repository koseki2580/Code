V, E = map(int,input().split())
INF = 10**100
INF2 = 10**20
box = [[INF] * (V) for _ in range(V)]
for i in range(E):
    s,t,d = map(int,input().split())
    box[s][t] = d
for i in range(V):
    box[i][i] = 0
for k in range(V):
    for i in range(V):
        for j in range(V):
            box[i][j] = min(box[i][j], box[i][k] + box[k][j])
flag = True
for i in range(V):
    if box[i][i] != 0:
        flag = False
        break
    for j in range(V):
        if box[i][j] >=  INF2:
            box[i][j] = 'INF'
if flag == True:
    for i in range(V):
        print(*box[i])
else:
    print("NEGATIVE CYCLE")