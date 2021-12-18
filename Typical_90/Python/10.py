N = int(input())
a = []
b = []
for i in range(N):
    c,p = map(int,input().split())
    if (c == 1):
        a.append(p)
        b.append(0)
    else:
        a.append(0)
        b.append(p)

s_a = [0]
s_b = [0]
for i in range(N):
    s_a.append(s_a[-1] + a[i])
    s_b.append(s_b[-1] + b[i])
Q = int(input())
for i in range(Q):
    l,r = map(int,input().split())
    l-=1
    a_ans = s_a[r] - s_a[l]
    b_ans = s_b[r] - s_b[l]
    print(str(a_ans) + " " + str(b_ans))