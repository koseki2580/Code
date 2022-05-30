N, K = map(int, input().split())
mod = 10**5

box = [-1] * (10**5+1)
next = [-1] * (10**5+1)
n = N
count = 0
while box[n] == -1:
    box[n] = count
    num = 0
    temp = n
    while (temp > 0):
        num += temp % 10
        temp //= 10
    next[n] = (n+num) % mod
    n += num
    n %= mod
    count += 1

# ループ
loop = count - box[n]
if K <= count:
    m = N
    for i in range(K):
        m = next[m]
    print(m)
else:

    # ループまでの回数を減らす
    K -= box[n]
    K %= loop

    m = n
    for i in range(K):
        m = next[m]
    print(m)
