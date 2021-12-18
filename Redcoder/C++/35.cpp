#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int N,W;
    cin >> N >> W;
    vector<int> v(N), w(N);
    rep(i,0,N){
        cin >> v[i] >> w[i];
    }
    vector<vector<int>> dp(N+5, vector<int>(W+5,0));
    rep(i,0,N){
        rrep(j,W,-1){
            dp[i+1][j] = dp[i][j];
            if (j + w[i] <= W ){
                dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j] + v[i]);
            }
        }
    }
    int ans = 0;
    rep(i,0,W+5){
        chmax(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}