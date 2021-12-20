#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 100100100;


int main() {
    int n,m;
    cin >> n >> m;
    vector<int> money(m);
    rep(i,0,m){
        cin >> money[i];
    }
    vector<vector<int>> dp(m+5, vector<int>(n+5,INF));
    dp[0][0] = 0;
    rep(i,0,m){
        rep(j,0,n+1){
            dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
            if (j + money[i] <= n){
                dp[i+1][j + money[i]] = min(dp[i][j] + 1, dp[i+1][j] + 1);
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}