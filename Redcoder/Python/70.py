def mod_pow(n,k,mod):
    ans = 1
    while k > 0:
        if k & 1 == 1:
            ans *= n
            ans %= mod
        n *= n
        n %= mod
        k >>= 1
    return ans

m, n = map(int,input().split())
print(mod_pow(m,n,10**9+7))

"""
pythonでは標準ライブラリのpowが
繰り返し二乗法を用いてるのでこちらを使う方が安全
pow(m,n,10**9+7)

"""