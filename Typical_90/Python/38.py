import math
from functools import reduce
def lcm_base(x, y):
    return (x * y) // math.gcd(x, y)
def lcm_list(numbers):
    return reduce(lcm_base, numbers, 1)
A,B = map(int,input().split())
a = lcm_base(A,B)
if a > 10**18:
    print("Large")
else:
    print(a)