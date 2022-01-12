import math

def getpos(e):
    rad = e / T * 360
    a = complex(L/2,0)
    aa = a * complex(math.cos(math.radians(-90)),math.sin(math.radians(-90)))
    aa = aa * complex(math.cos(math.radians(-rad)),math.sin(math.radians(-rad)))
    
    
    return [aa.real, aa.imag + L/2]

T = int(input())
L,X,Y = map(int,input().split())

Q = int(input())
for i in range(Q):
    e = int(input())
    a = getpos(e)
    ans = math.atan2(a[1], math.sqrt( (a[0] - Y)**2 + X**2 ))
    print(math.degrees(ans))