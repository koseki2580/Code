N,K = map(int,input().split())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
sa = 0
for i in range(N):
    sa += abs(A[i] - B[i])

if sa % 2 == K % 2 and K >= sa:
    print('Yes')
else:
    print('No')