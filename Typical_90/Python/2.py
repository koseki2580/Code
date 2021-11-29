N = int(input())
if N % 2 == 1:
    print()
else:
    for i in range(1 << N):
        ans = ''
        count = 0
        flag = True
        for j in range(N-1,-1,-1):
            if (i >> j & 1  == 1):
                ans += ')'
                count -= 1
            else:
                ans += '('
                count += 1
            if count < 0:
                flag = False
        if flag == True and count == 0:
            print(ans)