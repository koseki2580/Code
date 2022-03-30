N,Q = map(int,input().split())
A = [int(i) for i in input().split()]

m = 0
for i in range(Q):
    t,x,y = map(int,input().split())
    x -= 1
    y -= 1
    if t == 1:
        A[x-m], A[y-m] = A[y-m],A[x-m]
    elif t == 2:
        m += 1
        if m == N:
            m = 0
    else:
        print(A[x-m])