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
    int n;
    cin >> n;
    vector<P> box(n+1);
    rep(i,0,n){
        cin >> box[i].first >> box[i].second;
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1,INF));
    rep(i,0,n-1){
        dp[i][i+1] = box[i].first * box[i].second * box[i+1].second;
        dp[i+1][i+1] = 0;
    }
    dp[0][0] = 0;
    rep(i,2,n){
        rep(l,0,n-i){
            int r = l + i;
            rep(j,0,i){
                chmin(dp[l][r], dp[l][j+l] + dp[j+l+1][r] + box[l].first * box[r].second * box[j+l].second);
            }
        }
    }

    cout << dp[0][n-1] << endl;
    return 0;
}