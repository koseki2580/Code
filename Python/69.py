import math
# 素数判定
def is_prime(n):
    if n == 1: return False

    for k in range(2, int(math.sqrt(n)) + 1):
        if n % k == 0:
            return False

    return True
Q = int(input())
box = [0] * (10**5 + 5)
for i in range(3,10**5+3,2):
    box[i] = box[i-2]
    a = is_prime(i)
    if a == False:
        continue
    b = is_prime((i+1)//2)
    if b == True:
        box[i] += 1
for i in range(Q):
    l,r = map(int,input().split())
    ans = box[r] - box[l-2]
    print(ans)