#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1001001001;

int main() {
    int N;
    cin >> N;
    vector<int> R(N+1),B(N),W(N);
    rep(i,0,5){
        string s;
        cin >> s;
        rep(j,0,N){
            if (s[j] == 'R') ++R[j];
            if (s[j] == 'B') ++B[j];
            if (s[j] == 'W') ++W[j];
        }
    }
    vector<vector<int>> dp(N+1,vector<int>(3,INF));
    dp[0][0] = 5 - R[0];
    dp[0][1] = 5 - B[0];
    dp[0][2] = 5 - W[0];
    rep(i,1,N){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + (5 - R[i]);
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + (5 - B[i]);
        dp[i][2] = min(dp[i-1][1],dp[i-1][0]) + (5 - W[i]);
    }
    int ans = INF;
    rep(i,0,3){
        ans = min(ans,dp[N-1][i]);
    }
    cout << ans << endl;
    return 0;
}