import bisect
N = int(input())
S = list(input())

a = [[] for _ in range(10)]
for i in range(len(S)):
    a[int(S[i])].append(i)

ans = 0
for i in range(1000):
    b = ""
    if i < 10:
        b += "00" + str(i)
    elif i < 100:
        b += "0" + str(i)
    else:
        b += str(i)
    che = -1
    flag = True
    for i in range(3):
        num = bisect.bisect_right(a[int(b[i])], che) 
        if num == len(a[int(b[i])]):
            num -=1
        if len(a[int(b[i])]) >0 and che < a[int(b[i])][num]:
            che = a[int(b[i])][num]
        else:
            flag = False
    if flag == True:
        ans +=1
print(ans)
        
        