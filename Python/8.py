N = int(input())
a = []
b = []
for i in range(N):
    a_, b_ = map(int,input().split())
    a.append(a_)
    b.append(b_)
a.sort()
b.sort()
inn = a[N//2]
out = b[N//2]

ans = 0
for i in range(N):
    if  a[i] < inn:
        ans += 2*(inn - a[i])
        
        ans += out-inn
        if b[i] > out:
            ans += 2*(b[i] - out)
    else:
        ans += out-inn
        if b[i] > out:
            ans += 2*(b[i] - out)
print(ans)