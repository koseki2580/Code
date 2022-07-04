N = int(input())
box = []
for i in range(N):
    x, y = map(int, input().split())
    box.append([x, y])

box.sort()
X = box[N//2][0]
box = sorted(box, key=lambda x: x[1])
Y = box[N//2][1]

ans = 0
for i in range(N):
    ans += abs(box[i][0]-X) + abs(box[i][1]-Y)

print(ans)
