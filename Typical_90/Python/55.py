N, P, Q = map(int, input().split())
A = [int(i) % P for i in input().split()]

ans = 0
for i in range(N-4):
    for j in range(i+1, N-3):
        for k in range(j+1, N-2):
            for l in range(k+1, N-1):
                for p in range(l+1, N):
                    c = ((((A[i]*A[j] % P) * A[k] % P) * A[l] % P) * A[p] % P)
                    if c == Q:
                        ans += 1

print(ans)
