import itertools
import copy

N = int(input())
Q = []
for i in range(N):
    x,y = map(int,input().split())
    Q.append([x,y])

box = [[-1]*8 for _ in range(8)]
for i in range(N):
    x = Q[i][0]
    y = Q[i][1]
    for j in range(8):
        box[x][j] = 1
        box[j][y] = 1
        if x+j <8 and y+j < 8:
            box[x+j][y+j] = 1
        if x-j >= 0 and y-j >= 0:
            box[x-j][y-j] = 1
        if x+j <8 and y-j >= 0:
            box[x+j][y-j] = 1
        if x-j >= 0 and y+j < 8:
            box[x-j][y+j] = 1
        
a = [i for i in range(8)]
b = list(itertools.permutations(a))
for i in range(N):
    a.remove(Q[i][0])
check = []
for i in range(len(b)):
    
    flag = True
    for k in range(len(Q)):
        x = Q[k][0]
        y = Q[k][1]
        if b[i][x] != y:
            flag = False
            break
    if flag == False:
        continue
    flag2 = True
    for j in range(8):
        c = b[i][j]
        if box[j][c] != -1 and j in a:
            flag2 = False
            break
    if flag2 == True:
        check.append(b[i])

for i in range(len(check)):
    box2 = copy.deepcopy(box)
    flag = True
    for j in range(8):
        c = check[i][j]
        if box2[j][c] != -1 and j in a:
            flag = False
            break
        x = j
        y = c
        for k in range(8):
            box2[x][k] = 1
            box2[k][y] = 1
            if x+k <8 and y+k < 8:
                box2[x+k][y+k] = 1
            if x-k >= 0 and y-k >= 0:
                box2[x-k][y-k] = 1
            if x+k <8 and y-k >= 0:
                box2[x+k][y-k] = 1
            if x-k >= 0 and y+k < 8:
                box2[x-k][y+k] = 1
    if flag == True:
        ans = []
        for j in range(8):
            ans.append([j,check[i][j]])

ans_box = [['.']*8 for _ in range(8)]
for i in range(8):
    x = ans[i][0]
    y = ans[i][1]
    ans_box[x][y] = "Q"
    print("".join(ans_box[i]))

