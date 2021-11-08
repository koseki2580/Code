"""
ランレングス圧縮を用いた圧縮方法
書き方は最適化はわからないが行っていることは
AAABBBBBCC
の文字列があった場合に
A:3 B:5 C:2
のようにまとめた形で表現する圧縮方法
"""

N = int(input())
box = []
a = int(input())
box.append([a,1])
for i in range(N-1):
    a = int(input())
    if i % 2 == 1:
        if box[-1][0] == a:
            box[-1][1] += 1
        else:
            box.append([a,1])
        continue
    if box[-1][0] == a:
        box[-1][1] += 1
    else:
        box[-1][0] += 1
        box[-1][0] %= 2
        box[-1][1] += 1
        if len(box) >=2 and box[-1][0] == box[-2][0]:
            b,c = box.pop()
            box[-1][1] += c
ans = 0
for i in range(len(box)):
    if box[i][0] == 0:
        ans += box[i][1]
print(ans)