#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int mod = 10007;

int main() {
    int N;

    cin >> N;
    vector<int> box(N);
    string s;
    cin >> s;
    rep(i,0,N){
        if (s[i] == 'J') box[i] = 2;
        else if(s[i] == 'O') box[i] = 1;
        else box[i] = 0;
    }
    int pa = 1 << 3;
    vector<vector<int>> dp(N+1,vector<int>(pa,0));
    rep(i,0,pa){
        // 0日目の責任者と最初はJ君が持っているのでこの二人が参加している日を確認
        int xx = (i >> (box[0])) & 1;
        int yy = (i >> 2) & 1 ;

        if ( xx == 1 && yy == 1 ){
            dp[0][i] = 1;
        }
    }
    /*
        dp[i+1][x] += dp[i][y]
        i+1日目にx（２進数でbitが立っているところ）が参加する通り数は
        i+1日目に責任者が参加している　かつ　i日目に参加している人がi+1日目にも参加している
    */
    rep(i,1,N){
        rep(x,0,pa){
            // 責任者が参加しているか確認
            int aa = x >> (box[i]) & 1;
            if (aa == 0){
                continue;
            }
            rep(y,0,pa){
                // 前日の参加者が参加しているか
                int xx = x & y;
                if (xx >= 1){
                    dp[i][x] += dp[i-1][y];
                    dp[i][x] %= mod;
                }
            }
        }
    }
    int ans = 0;
    rep(i,0,pa){
        ans += dp[N-1][i];
    }
    ans %= mod;
    cout << ans << endl;
    return 0;
}