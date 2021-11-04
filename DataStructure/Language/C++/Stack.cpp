#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {

    // 初期化
    stack<int> s;
    // push　要素を後ろに追加
    s.push(1);
    s.push(2);
    s.push(3);
    // 一番後ろの要素を確認
    cout << s.top() << endl; // 3  s:[1,2,3]
    s.push(4);
    cout << s.top() << endl; // 4  s:[1,2,3,4]

    // pop 一番後ろ（一番新しい）要素を取り除く
    s.pop();
    s.pop();
    cout << s.top() << endl; // 2  s:[1,2]
    return 0;
}