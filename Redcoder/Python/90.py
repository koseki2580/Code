import math
def check(num):

    for i in range(N):
        for j in range(M):
            if num + box[i][2] > math.sqrt( (con[j][0] - box[i][0])**2 + (con[j][1] - box[i][1])**2 ):
                return False
    for i in range(M):
        for j in range(i+1,M):
            if 2 * num > math.sqrt( (con[j][0] - con[i][0])**2 + (con[j][1] - con[i][1])**2 ):
                return False
    return True

N,M = map(int,input().split())
box = []
for i in range(N):
    x,y,r = map(int,input().split())
    box.append([x,y,r])
con = []
for i in range(M):
    x,y = map(int,input().split())
    con.append([x,y])

l = 0
r = 10**5
while r - l > 0.0000000001:
    mid = (l+r)/2
    if check(mid) == True:
        l = mid
    else:
        r = mid
if M == 0:
    aa = sorted(box, key=lambda x: x[2])  

    l = aa[0][2]
print(l)