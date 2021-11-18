while True:
    n,w,d = map(int,input().split())
    if n == w == d == 0:
        break
    box = []
    box.append([w,d])
    for i in range(n):
        p,s  = map(int,input().split())
        p -= 1
        
        x,y = box.pop(p)
        cc = s % (x+y)
        if (x < cc):
            cc -= x
            con1 = [x,cc,x*cc]
            con2 = [x,y - cc,x*(y-cc)]
        else:
            con1 = [cc,y,y*cc]
            con2 = [x-cc,y ,y*(x-cc)]
        if con1[2] >= con2[2]:
            box.append([con2[0],con2[1]])
            box.append([con1[0],con1[1]])
        else:
            box.append([con1[0],con1[1]])
            box.append([con2[0],con2[1]])
    ans = []
    for i in range(len(box)):
        ans.append(box[i][0]*box[i][1])
    ans.sort()
    print(*ans)