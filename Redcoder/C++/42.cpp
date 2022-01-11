#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int inf = 1001001001;

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> n(N),m(M);
    rep(i,0,N){
        cin >> n[i];
    }
    rep(i,0,M){
        cin >> m[i];
    }
    vector<vector<int>> dp(M+1, vector<int>(N+1,inf));
    dp[0][0] = 0;
    rep(i,0,M){
        rep(j,0,N){
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + n[j] * m[i]);
            if (N - j <= M - i){
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            }
        }
    }
    int ans = inf;
    rep(i,0,M+1){
        ans = min(ans, dp[i][N]);
    }
    cout << ans << endl;
    return 0;
}