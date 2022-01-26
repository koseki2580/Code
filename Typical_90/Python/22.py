import math
from functools import reduce

def gcd(*numbers):
    return reduce(math.gcd, numbers)

def gcd_list(numbers):
    return reduce(math.gcd, numbers)

A,B,C = map(int,input().split())

box = [A,B,C]
a_gcd = gcd_list(box)
ans = A // a_gcd + B // a_gcd + C // a_gcd -3
print(ans)