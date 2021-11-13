import math
a,b,x = map(int,input().split())

if a*a*b/2 < x:
    y = 2*x /a/a - b
    cos = (b - y) / math.sqrt(a*a + (b-y)*(b-y))
    ans = 90 - math.degrees(math.acos(cos))
else:
    y = 2 * x / a / b
    cos = b / math.sqrt(y*y + b*b)
    ans = 90 - math.degrees(math.acos(cos))
print(ans)