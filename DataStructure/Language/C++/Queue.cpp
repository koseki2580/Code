#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {

    // 初期化
    queue<int> s;
    // push　要素を後ろに追加
    s.push(1);
    s.push(2);
    s.push(3);
    // 一番前の要素を確認
    cout << s.front() << endl; // 1  s:[1,2,3]
    s.push(4);

    // pop　一番前の要素を取り除く
    s.pop();
    cout << s.front() << endl; // 2  s:[2,3,4]
    s.pop();
    cout << s.front() << endl; // 3  s:[3,4]
    return 0;
}