from statistics import mode


N, K = map(int, input().split())
mod = 10**9+7
ans = 1
if N < 3:
    for i in range(N):
        ans *= K
        ans %= mod
        K -= 1
else:
    ans *= K
    ans %= mod
    K -= 1
    ans *= K
    ans %= mod
    K -= 1
    ans *= pow(K, N-2, mod)
    ans %= mod
print(ans)
