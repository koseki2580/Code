N = int(input())
a = [int(i) for i in input().split()]
box = {}
num = [1]
for i in range(N):
    num.append(num[-1] * 2)
for i in range(1 << N):
    count = 0
    for j in range(N):
        if i & (1 << j) == num[j]:
            count += a[j]
    box[count] = 1

q = int(input())
n = [int(i) for i in input().split()]
for i in range(q):
    try:
        box[n[i]] += 1
        print("yes")
    except:
        print("no")