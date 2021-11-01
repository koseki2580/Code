"""
500msなのでPythonでは間に合わない
けどこれであってると考えられる
"""

N, M = map(int,input().split())
K = int(input())
box = []
for i in range(N):
    a = list(input())
    box.append(a)

J = [[0]*(M+1) for _ in range(N+1)]
O = [[0]*(M+1) for _ in range(N+1)]
I = [[0]*(M+1) for _ in range(N+1)]

for i in range(N):
    for j in range(M):
        if box[i][j] == 'J':
            J[i+1][j+1] = 1
        elif box[i][j] == 'O':
            O[i+1][j+1] = 1
        elif box[i][j] == 'I':
            I[i+1][j+1] = 1

for i in range(1,N+1):
    for j in range(1,M+1):
        J[i][j] += J[i][j-1]
        O[i][j] += O[i][j-1]
        I[i][j] += I[i][j-1]

for i in range(1,N+1):
    for j in range(1,M+1):
        J[i][j] += J[i-1][j]
        O[i][j] += O[i-1][j]
        I[i][j] += I[i-1][j]

for i in range(K):
    ans = []
    a,b,c,d = map(int,input().split())
    ans.append(J[c][d] - J[c][b-1] - J[a-1][d] + J[a-1][b-1])
    ans.append(O[c][d] - O[c][b-1] - O[a-1][d] + O[a-1][b-1])
    ans.append(I[c][d] - I[c][b-1] - I[a-1][d] + I[a-1][b-1])
    print(*ans)