m = int(input())
box = []
for i in range(m):
    a,b = map(int,input().split())
    box.append([a,b])
check_box = []
for i in range(m):
    check_box.append([box[i][0] - box[0][0], box[i][1] - box[0][1]])

n = int(input())
box2 = {}
for i in range(n):
    a,b = map(int,input().split())
    box2[a,b] = 1

for i in box2.keys():
    x = i[0]
    y = i[1]
    count = 0
    for j in range(m):
        try:
            box2[x + check_box[j][0],y + check_box[j][1]] += 1
            count += 1
        except:
            break
    if count == m:
        ans = [x - box[0][0], y - box[0][1]]
        break
print(*ans)