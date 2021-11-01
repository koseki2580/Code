A, B, C, X, Y = map(int,input().split())
ans = 10**10
if X < Y:
    ab = C * (2*X)
    b = (Y-X)*B
    ans = min (ans, b+ab)
    
    ab = C*(2*Y)
    ans = min(ans, ab)
    
    ans = min(ans, X*A+Y*B)
else:
    ab = C * (2*Y)
    a = (X-Y)*A
    ans = min (ans, a+ab)
    
    ab = C*(2*X)
    ans = min(ans, ab)
    
    ans = min(ans, X*A+Y*B)

print(ans)