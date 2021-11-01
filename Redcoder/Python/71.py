N, Q = map(int,input().split())
a = [int(i) for i in input().split()]
c = [int(i)-1 for i in input().split()]
s = [0]
mod = 10**9+7
for i in range(N-1):
    s.append((s[i] + pow(a[i], a[i+1], mod)) % mod)

ans = 0
st = 0
for i in range(Q):
    b = c[i]
    flag = True
    if st > b:
        st, b = b,st
        flag = False
    ans += s[b] - s[st]
    ans %= mod
    if flag == True:
        st  = b
ans += s[st]
ans %= mod
print(ans)