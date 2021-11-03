#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

ll inf = 100100100000;

int main() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = inf;
    ll count;
    rep(i,0,max(X,Y)+1){
        count = C*2*i + A*max(X-i,0)+B*max(Y-i,0);
        ans = min(ans,count);
    }
    cout << ans << endl;
    return 0;
}