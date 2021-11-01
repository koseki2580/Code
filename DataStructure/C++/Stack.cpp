#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl; // 3  s:[1,2,3]
    s.push(4);
    cout << s.top() << endl; // 4  s:[1,2,3,4]
    s.pop();
    s.pop();
    cout << s.top() << endl; // 2  s:[1,2]
    return 0;
}