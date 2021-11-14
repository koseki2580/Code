from collections import deque
while True:
    N = int(input())
    if N == 0:
        break
    box1 = []
    box2 = []
    for i in range(5):
        box1.append(deque())
        box2.append(deque())
    box = []
    for i in range(N):
        a = list(map(int, input().split()))
        box.append(a)
    for i in range(N-1,-1,-1):
        for j in range(5):
            box1[j].append(box[i][j])
        
        
    ans = 0
    change = 0
    while True:
        flag = True
        
        if change % 2 == 0:
            while (len(box1[0]) + len(box1[1]) + len(box1[2]) + len(box1[3]) + len(box1[4])) > 0:
                con = []
                for i in range(5):
                    if (len(box1[i]) > 0):
                        con.append(box1[i].popleft())
                    else:
                        con.append(-1)
                num = [[con[0],1]]
                for i in range(1,5):
                    if num[-1][0] == con[i]:
                        num[-1][1] += 1
                    else:
                        num.append([con[i],1])
                if len(num) <= 3:
                    for i in range(len(num)):
                        if num[i][0] != -1 and num[i][1] >= 3:
                            ans += num[i][0] * num[i][1]
                            flag = False
                            num[i][0] = -1
                add = []
                for i in range(len(num)):
                    for j in range(num[i][1]):
                        add.append(num[i][0])
                for i in range(5):
                    if add[i] != -1:
                        box2[i].append(add[i])
            change += 1
        else:
            while (len(box2[0]) + len(box2[1]) + len(box2[2]) + len(box2[3]) + len(box2[4])) > 0:
                con = []
                for i in range(5):
                    if (len(box2[i]) > 0):
                        con.append(box2[i].popleft())
                    else:
                        con.append(-1)
                num = [[con[0],1]]
                for i in range(1,5):
                    if num[-1][0] == con[i]:
                        num[-1][1] += 1
                    else:
                        num.append([con[i],1])
                if len(num) <= 3:
                    for i in range(len(num)):
                        if num[i][0] != -1 and num[i][1] >= 3:
                            ans += num[i][0] * num[i][1]
                            flag = False
                            num[i][0] = -1
                add = []
                for i in range(len(num)):
                    for j in range(num[i][1]):
                        add.append(num[i][0])
                for i in range(5):
                    if add[i] != -1:
                        box1[i].append(add[i])
            change += 1
        if flag == True:
            break
    print(ans)
    