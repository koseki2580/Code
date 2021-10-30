import bisect

N, M = map(int,input().split())
a = []
for i in range(N):
    a.append(int(input()))

box = []
for i in range(N):
    box.append(a[i])
    for j in range(N):
        box.append(a[i] + a[j])
box.sort()
ans = 0
for i in range(len(box)):
    b = M - box[i]
    c = bisect.bisect_right(box,b)-1
    if box[i] + box[c] <= M:
        #print(str(box[i]) + ' ' + str(box[c]) + " " + str(box[i] + box[c]))
        ans = max(ans,box[i] + box[c])
    
        
print(ans)