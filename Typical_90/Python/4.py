H, W = map(int,input().split())
A = []
for i in range(H):
    b = list(map(int,input().split()))
    A.append(b)
h_sum = [0] * H
w_sum = [0] * W
for i in range(H):
    for j in range(W):
        h_sum[i] += A[i][j]
        w_sum[j] += A[i][j]
ans = []
for i in range(H):
    c = []
    for j in range(W):
        c.append(h_sum[i] + w_sum[j] - A[i][j]) 
    ans.append(c)
for i in range(H):
    print(*ans[i])