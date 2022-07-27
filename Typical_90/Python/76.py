

N = int(input())
A = [int(i) for i in input().split()]

l = 0
r = 0
num = sum(A)/10
a = 0
ans = "No"
flag = True
while (flag == True):
    while a < num:
        a += A[r]
        r += 1
        r %= N
    if a == num:
        ans = "Yes"
        break
    while a > num:
        a -= A[l]
        l += 1
        l %= N
        if l == 0:
            flag = False
    if a == num:
        ans = "Yes"
        break


print(ans)
