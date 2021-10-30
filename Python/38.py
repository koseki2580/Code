    """
    計算時間に間に合わない
    PyPyなら間に合うだろう
    C++で書いたのでは通ったのでdp処理自体には問題なし
    
    10**7が間に合わないはきつい
    """

N =  int(input())
for a in range(N):
    X = input()
    Y = input()
    dp = [[0]*(len(X)+5) for _ in range(len(Y)+5)]
    for i in range(len(Y)):
        for j in range(len(X)):
            if X[j] == Y[i]:
                dp[i+1][j+1] = max(dp[i][j] + 1, dp[i+1][j],dp[i][j+1])
            else:
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])
    print(dp[len(Y)][len(X)])
    