N, Q = map(int,input().split())
box = []
# ++ +- -+ --
# マンハッタン距離なので
# グラフの右上・右下・左上・左下の４点のどこかがどの点からでも距離が最大となる
# そのため、最初に４点を求めることでO(max(N,Q))で最大値を求めることが可能
INF = 10**9 + 7
max_num = [0] * 4
max_flag = [False] * 4 
max_pos =[[INF,INF],[INF,-INF],[-INF,INF],[-INF,-INF]]
for i in range(N):
    x,y = map(int,input().split())
    box.append([x,y])
    if  0<= x and 0 <= y:
        if abs(x) + abs(y) > max_num[0]:
            max_num[0] = abs(x) + abs(y)
            max_pos[0][0] = x
            max_pos[0][1] = y
            max_flag[0] = True
    if 0 <= x and y < 0:
        if abs(x) + abs(y) > max_num[1]:
            max_num[1] = abs(x) + abs(y)
            max_pos[1][0] = x
            max_pos[1][1] = y
            max_flag[1] = True
    if x < 0 and 0 <= y:
        if abs(x) + abs(y) > max_num[2]:
            max_num[2] = abs(x) + abs(y)
            max_pos[2][0] = x
            max_pos[2][1] = y
            max_flag[2] = True
    if x < 0 and y < 0:
        if abs(x) + abs(y) > max_num[3]:
            max_num[3] = abs(x) + abs(y)
            max_pos[3][0] = x
            max_pos[3][1] = y
            max_flag[3] = True

for i in range(Q):
    q = int(input())
    q -= 1
    x = box[q][0]
    y = box[q][1]
    ans = 0
    for j in range(4):
        if max_flag[j] == True:
            ans = max(ans, abs(max_pos[j][0] - x) + abs(max_pos[j][1] - y))
    print(ans)