#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int N;
    cin >> N;
    rep(i,0,N){
        string s,t;
        cin >> s >> t;
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1, 0));
        rep(i,1,s.size()+1){
            rep(j,1,t.size()+1){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if (s[i-1] == t[j-1]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] +1);
                }
            }
        }
        cout << dp[s.size()][t.size()] << endl;
    }

    return 0;
}