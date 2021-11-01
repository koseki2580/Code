N, M , Q = map(int,input().split())
box = [[0] * (N+1) for _ in range(N+1)]
for i in range(M):
    l,r = map(int,input().split())
    l -= 1
    box[l][r] +=1

for i in range(N):
    for j in range(1,1+N):
        box[i][j] += box[i][j-1]

for i in range(N-1,-1,-1):
    for j in range(1+N):
        box[i][j] += box[i+1][j]
        
        # if j - 1 >= 0:
        #     box[i][j] -= box[i+1][j-1]
for i in range(Q):
    l,r = map(int,input().split())
    print(box[l-1][r])