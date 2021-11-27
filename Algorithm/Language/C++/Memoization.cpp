#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

/*
フィボナッチ数列(Fibonacci number)
f(n) = f(n-1) + f(n-2)
1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181・・・
の第n項目を求める

ただの再帰処理だと上記の計算量はO(2^n)となる
しかし、メモ化処理を用いることでO(n)まで減らすことが可能になる
*/
const int MAX_NUM = 100100100;
vector<ll> memo(MAX_NUM, -1);
ll Fibonacci(int n){
    // 初項を1として数えた場合に一致するように記載
    // 以下のif文がないと無限ループする
    if (memo[n] != -1) return memo[n];
    return memo[n] = Fibonacci(n-1) + Fibonacci(n-2);
}
int main() {

    memo[1] = 1;
    memo[2] = 1;
    cout << Fibonacci(50) << endl; // 12586269025
    cout << Fibonacci(30) << endl; // 832040
    return 0;
}