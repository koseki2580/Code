import math
import itertools
N = int(input())
box = []
for i in range(N):
    x,y = map(int,input().split())
    box.append([x,y])

a = [i for i in range(N)]
b = list(itertools.permutations(a))
ans = 0
for i in range(len(b)):
    for j in range(1,len(b[i])):
        c = b[i][j-1]
        d = b[i][j]
        ans += math.sqrt((box[c][0] - box[d][0])**2 + (box[c][1] - box[d][1])**2)

print(ans/len(b))