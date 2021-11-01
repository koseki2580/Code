def check(mid, num):
    if mise[mid] <= num:
        return True
    return False


L = int(input())
n = int(input())
m = int(input())

mise = [0,L]
for i in range(n-1):
    a = int(input())
    mise.append(a)
mise.sort()
takuhai = []
for i in range(m):
    b = int(input())
    takuhai.append(b)

ans = 0
for i in range(m):
    l = 0
    r = n+1
    while r-l > 1:
        mid = (l+r)//2
        if check(mid, takuhai[i]) == True:
            l = mid
        else:
            r = mid
    l+=1

    ans += min(abs(mise[l]- takuhai[i]), abs(mise[l-1]- takuhai[i]))
print(ans)