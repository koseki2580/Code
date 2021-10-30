H, W, K, V = map(int,input().split())
A = []

for i in range(H):
    a = list(map(int,input().split()))
    A.append(a)
    

box = [[0]*(W+1) for _ in range(H+1)]
for i in range(H):
    for j in range(W):
        box[i+1][j+1] = A[i][j]
for i in range(H):
    for j in range(1,1+W):
        box[i+1][j] += box[i][j]

for i in range(1,H+1):
    for j in range(W):
        box[i][j+1] += box[i][j]
ans = 0
for i in range(1,1+H):
    for j in range(1,1+W):
        con = box[i][j]
        if con + (K * ((i) * (j))) <= V:
            ans = max(ans, (i) * (j))
        for k in range(i):
            for l in range(j):
                con = box[i][j]
                con -= box[i][l]
                con -= box[k][j]
                con += box[k][l]
                if con + (K * ((i - k) * (j - l))) <= V:
                    ans = max(ans, (i - k) * (j - l))
print(ans)