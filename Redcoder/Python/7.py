N = int(input())
box = {}
box2 = []
for i in range(N):
    a,b = map(int,input().split())
    box2.append([a,b])
    box[a,b] = 1

box2.sort()
ans = 0
for i in range(N):
    for j in range(i+1,N):
        c = box2[i]
        d = box2[j]
        x = c[0] - d[0]
        y = c[1] - d[1]
        try:
                
            if box[c[0] + -y, c[1] + x] == 1:
                if box[d[0] + -y, d[1] + x] == 1:
                    ans = max(ans,  x ** 2 + y**2)
            elif box[c[0] + -x, c[1] - y] == 1:
                if box[d[0] + -x, d[1] - y] == 1:
                    ans = max(ans, x ** 2 + y**2)
            elif box[c[0] + +y, c[1] - x] == 1:
                if box[d[0] + +y, d[1] - x] == 1:
                    ans = max(ans, x ** 2 + y**2)
        except:
            dd = 1
print(ans)