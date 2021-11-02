while True:
    n = int(input())
    if n == 0:
        break
    box = [0] * (24*60*60)
    for i in range(n):
        a = list(input().split())
        st = int(a[0][:2])*(60*60) + int(a[0][3:5])*60 + int(a[0][6:])
        en = int(a[1][:2])*(60*60) + int(a[1][3:5])*60 + int(a[1][6:])
        box[st] += 1
        box[en] -= 1
    s = [0] 
    for i in range(len(box)):
        s.append(s[-1] + box[i])
    ans = 0
    for i in range(len(s)):
        ans = max(ans,s[i])
    print(ans)