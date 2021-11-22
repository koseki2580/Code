import math
from functools import reduce

def lcm_base(x, y):
    return (x * y) // math.gcd(x, y)

def lcm_list(numbers):
    return reduce(lcm_base, numbers, 1)

N,M = map(int,input().split())
A = [int(i)//2 for  i in input().split()]
count = 0
for i in range(N):
    if A[i] % 2 == 0:
        count += 1
    else:
        count -= 1
if count == -N:
    a = lcm_list(A)
    ans = int(M / a / 2 + 0.5)
elif count == N:
    box = set()
    a = lcm_list(A)
    ans = int(M / a / 2 + 0.5)
    for i in range(N):
        con = 1
        while (A[i] % 2 == 0):
            con += 1
            A[i] //= 2
        box.add(con)
        if len(box) != 1:
            ans = 0
            break
        
else:
    ans = 0

print(ans)

