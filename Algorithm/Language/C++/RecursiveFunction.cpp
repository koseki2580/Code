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
*/
ll Fibonacci(int n){
    // 初項を1として数えた場合に一致するように記載
    // 以下のif文がないと無限ループする
    if (n == 1 || n == 2) return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}
int main() {


    cout << Fibonacci(5) << endl; // 5
    cout << Fibonacci(6) << endl; // 8
    return 0;
}