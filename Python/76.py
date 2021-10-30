N = int(input())
A = [int(i) for i in input().split()]
s = [0]
for i in range(N):
    s.append(s[i] + A[i])

for i in range(N):
    ans = 0
    l = 0
    for j in range(i+1,N+1):
        ans = max(ans,s[j] - s[l])
        l += 1
    print(ans)
