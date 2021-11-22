import math
P = float(input())

l = 0
r = 10**10
"""
P * 2^(-2x/3) + xの微分を考える 
P * (-2/3) * 2^(-2x/3) * log(2) + 1 
(1/2)^(2x/3) * log(2) = 3 / (2*P)となるxを求めると最小値が求まる
後は二分探索で値を小さくしていくだけ求まる
"""
check = 3 / (2*P ) 
while r - l > 0.000001:
    mid = (r+l) /2
    a = pow(1/2, (2*mid)/3)* math.log(2,math.e)
    if (a <= check):
        r = mid
    else:
        l = mid
print(P/pow(2,2*l/3) + l)