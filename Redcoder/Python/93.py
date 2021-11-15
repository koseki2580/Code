""" 
swapを上手く使えば分岐を消せるのでもう少しコードが短くなりそう
"""

from collections import deque
H,W,K = map(int,input().split())
box = [];
for i in range(H):
    a = []
    b = input()
    for i in range(W):
        a.append(int(b[i]))
    box.append(a)
con1 = [];
con2 = [];

for i in range(W):
    con1.append(deque())
    con1.append(deque())
ans = 0
for ii in range(H):
    for jj in range(W):
        con1 = [];
        con2 = [];

        for k in range(W):
            con1.append(deque())
            con2.append(deque())
            
        for k in range(H):
            for l in range(W):
                if k != ii or l != jj:
                    con1[l].appendleft(box[k][l])
        ans2 = 0
        change = 0
        while True:
            
            flag = True
            count = 0
            if change % 2 == 0:
                aa = 0
                for i in range(W):
                    aa += len(con1[i])
                while (aa) > 0:
                    
                    con = []
                    for i in range(W):
                        if (len(con1[i]) > 0):
                            con.append(con1[i].popleft())
                        else:
                            con.append(-1)
                    num = [[con[0],1]]
                    for i in range(1,W):
                        if num[-1][0] == con[i]:
                            num[-1][1] += 1
                        else:
                            num.append([con[i],1])
                    bb = -1
                    for i in range(len(num)):
                        if bb < num[i][1]:
                            bb = num[i][1]
                    if bb >= K:
                        for i in range(len(num)):
                            if num[i][0] != -1 and num[i][1] >= K:
                                count += num[i][0] * num[i][1]
                                flag = False
                                num[i][0] = -1
                    add = []
                    for i in range(len(num)):
                        for j in range(num[i][1]):
                            add.append(num[i][0])
                    for i in range(W):
                        if add[i] != -1:
                            con2[i].append(add[i])
                    aa = 0
                    for i in range(W):
                        aa += len(con1[i])
                change += 1
            else:
                aa = 0
                for i in range(W):
                    aa += len(con2[i])
                while (aa) > 0:
                    con = []
                    for i in range(W):
                        if (len(con2[i]) > 0):
                            con.append(con2[i].popleft())
                        else:
                            con.append(-1)
                    num = [[con[0],1]]
                    for i in range(1,W):
                        if num[-1][0] == con[i]:
                            num[-1][1] += 1
                        else:
                            num.append([con[i],1])
                    bb = -1
                    for i in range(len(num)):
                        if bb < num[i][1]:
                            bb = num[i][1]
                    if bb >= K:
                        for i in range(len(num)):
                            if num[i][0] != -1 and num[i][1] >= K:
                                count += num[i][0] * num[i][1]
                                flag = False
                                num[i][0] = -1
                    add = []
                    for i in range(len(num)):
                        for j in range(num[i][1]):
                            add.append(num[i][0])
                    for i in range(W):
                        if add[i] != -1:
                            con1[i].append(add[i])
                    aa = 0
                    for i in range(W):
                        aa += len(con2[i])
                
                change += 1
            ans2 += pow(2,change-1) * count
            if flag == True:
                break
        ans = max(ans,ans2)
print(ans)