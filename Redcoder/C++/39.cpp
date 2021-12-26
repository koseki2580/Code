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
    vector<int> A(N);
    rep(i,0,N){
        cin >> A[i];
    }
    vector<vector<ll>> dp(N,vector<ll>(21, 0));
    dp[1][A[0]] = 1;
    rep(i,1,N-1){
        rep(j,0,21){
            if (dp[i][j] != 0){
                // たす
                if (j + A[i] <= 20){
                    dp[i+1][j + A[i]] += dp[i][j];
                }
                // ひく
                if (j - A[i] >= 0){
                    dp[i+1][j - A[i]] += dp[i][j];
                }
            }
        }
    }
    cout << dp[N-1][A[N-1]] << endl;
    return 0;
}