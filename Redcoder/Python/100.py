N = int(input())
s = 1
while (2*N > (s-1)*s):
    s+=1
if 2*N != s*(s-1):
    print('No')
else:
    print('Yes')
    print(s)
    box = [[0]*(s-1) for _ in range(s)]
    point = 1
    for i in range(s-1):
        box[i][i] = point
        nn = point
        point +=1
        for j in range(i+1,s-1):
            box[i][j] = point
            point += 1
        for j in range(i+1,s):
            box[j][i] =nn
            nn += 1
    for i in range(s):
        print(s-1,end=" ")
        print(*box[i])