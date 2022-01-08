N = int(input())
A,B,C = map(int,input().split())
ans = 10**9
for i in range(10001):
    for j in range(10001-i):
        c = N - A*i - B*j
        if c >= 0 and c % C == 0:
            k = c //C
            if i + j + k <10000:
                ans = min(ans,i + j + k)
print(ans)