"""
以下の回答ではPythonでは時間が間に合わないがC++では余裕で間に合う
コメントの一番下は他人の回答でPythonで通る回答
"""
n = 1
dp = [10**9] * (10**6+5)
dp2 = [10**9] * (10**6+5)

while True:
    if n*(n+1)*(n+2) //6 >= 10**6:
        break
    num = n*(n+1)*(n+2) //6 
    count = 1
    for i in range(num,10**6+1):
        if i % num == 0:
            dp[i] = count
            count += 1
        else:
            dp[i] = min(dp[i], dp[i-num]+1)
    if num % 2 == 1:
        count = 1
        for i in range(num,10**6+1):
            if i % num == 0:
                dp2[i] = count
                count += 1
            else:
                dp2[i] = min(dp2[i], dp2[i-num]+1)
    n += 1

while True:
    N = int(input())
    if N == 0:
        break
    
                
    
    print(str(dp[N]) + " " + str(dp2[N]))
"""
    
box = []
n = 1
nn = 10**6
while True:
    if n*(n+1)*(n+2) //6 >= 10**6:
        break
    box.append(n*(n+1)*(n+2) //6)
    n += 1
dp = [[10**9+7] * (nn+5) for _ in range(len(box)+1)]
for i in range(len(box)):
    dp[i][0] = 0
    
for i in range(len(box)):
    for j in range(nn+1):
        dp[i+1][j] = min(dp[i][j], dp[i+1][j])
        if j + box[i] <= nn:
            dp[i+1][j + box[i]] = min(dp[i][j + box[i]], dp[i][j] + 1, dp[i+1][j]+1)
dp2 = [[10**9+7] * (nn+5) for _ in range(len(box)+1)]
for i in range(len(box)):
    dp2[i][0] = 0
    
for i in range(len(box)):
    for j in range(nn+1):
        dp2[i+1][j] = min(dp2[i][j], dp2[i+1][j])
        if box[i] % 2 == 1 and j + box[i] <= nn:
            dp2[i+1][j + box[i]] = min(dp2[i][j + box[i]], dp2[i][j] + 1, dp2[i+1][j]+1)
while True:
    N = int(input())
    if N == 0:
        break
    
                
    
    print(str(dp[len(box)][N]) + " " + str(dp2[len(box)][N]))
    
n = 1
def solve():
    rec = [1000000] * 1000000
    rec[0] = 0
    odd_rec = rec.copy()
    
    for i in range(1, 181):
        t = i * (i + 1) * (i + 2) // 6
        for i, tpl in enumerate(zip(rec[t:t*3+1], rec), start=t):
            a, b = tpl
            b += 1
            if b < a:
                rec[i] = b
        if t % 2:
            for i, tpl in enumerate(zip(odd_rec[t:t*34+1], odd_rec), start=t):
                a, b = tpl
                b += 1
                if b < a:
                    odd_rec[i] = b
    
    while True:
        n = int(input())
        print(rec[n], odd_rec[n])

solve()

"""