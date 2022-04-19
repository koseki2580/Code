N = int(input())
A = [int(i)%46 for i in input().split()]
B = [int(i)%46 for i in input().split()]
C = [int(i)%46 for i in input().split()]
a = [0] * 46
b = [0] * 46
c = [0] * 46
for i in range(N):
    a[A[i]] += 1
    b[B[i]] += 1
    c[C[i]] += 1

ans = 0
for i in range(46):
    for j in range(46):
        for k in range(46):
            if (i + j + k) % 46 == 0:
                ans += a[i] * b[j] * c[k]
print(ans)