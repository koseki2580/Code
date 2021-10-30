n, m = map(int,input().split())
a = []
for i in range(n-1):
    b = int(input())
    a.append(b)
c = []
for i in range(m):
    d = int(input())
    c.append(d)

s = [0]
for i in range(n-1):
    s.append(s[i] + a[i])
ans = 0
mod = 10**5
mae = 0
for i in range(m):
    ans += abs(s[mae + c[i]] - s[mae])
    mae += c[i]
    ans %= mod
print(ans)