"""
フィボナッチ数列(Fibonacci number)
f(n) = f(n-1) + f(n-2)
1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181・・・
の第n項目を求める

ただの再帰処理だと上記の計算量はO(2^n)となる
しかし、メモ化処理を用いることでO(n)まで減らすことが可能になる
"""

def Fibonacci(n):
    # 初項を1として数えた場合に一致するように記載
    # 以下のif文がないと無限ループする
    if memo[n] != -1:
        return memo[n]

    memo[n] = Fibonacci(n-1) + Fibonacci(n-2)
    return memo[n]

memo = [-1] * 10**5
memo[1] = 1
memo[2] = 1
print(Fibonacci(50)) # 12586269025
print(Fibonacci(30)) # 832040