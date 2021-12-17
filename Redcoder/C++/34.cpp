#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int n;
    cin >> n;
    vector<int> dp(n+5,0);
    dp[0] = 1;
    dp[1] = 1;
    rep(i,2,n+2){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << endl;
    return 0;
}