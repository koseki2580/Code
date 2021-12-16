import math
import bisect
def radlist(num):
    radlist = []
    for i in range(N):
        if (box[num][0] == box[i][0] and box[num][1] == box[i][1]):
            
            continue
        X = box[i][0] - box[num][0] 
        Y = box[i][1] - box[num][1] 
        rad = math.degrees(math.atan2(Y,X))
        if (rad < 0):
            rad = 360 + rad 
        if rad >= 360:
            rad -= 360
        radlist.append(rad)
    radlist.sort()
    return radlist

def radin180(num):
    if num > 180:
        num = 360 - num
    return num

N = int(input())
box = []
for i in range(N):
    x,y = map(int,input().split())
    box.append([x,y])

ans = 0
for i in range(N):
    rads = radlist(i)
    for j in range(N-1):
        secondpoint = rads[j]
        if secondpoint < 180:
            searchpoint = secondpoint + 180
            num = bisect.bisect_left(rads,searchpoint)
            if (num == N-1):
                num -= 1
            rad = radin180(abs(secondpoint - rads[num]))
            ans = max(ans, rad)
            rad = radin180(abs(secondpoint - rads[num-1]))
            ans = max(ans, rad)
        else:
            searchpoint = secondpoint - 180
            num = bisect.bisect_left(rads,searchpoint)
            if (num == N-1):
                num = 0
            rad = radin180(abs(secondpoint - rads[num]))
            ans = max(ans, rad)
            rad = radin180(abs(secondpoint - rads[num-1]))
            ans = max(ans, rad)
print(ans)