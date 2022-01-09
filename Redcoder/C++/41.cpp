#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int D,N;
    cin >> D >> N;
    vector<int> days(D);
    rep(i,0,D){
        cin >> days[i];
    }
    vector<int> A(N),B(N),C(N);
    rep(i,0,N){
        cin >> A[i] >> B[i] >> C[i];
    }
    vector<vector<int>> dp(D+5, vector<int>(N+5, 0));
    rep(i,1,D){
        rep(j,0,N){
            if (A[j] > days[i-1] || days[i-1] > B[j]){
                continue;
            }

            rep(k,0,N){
                if (A[k] <= days[i] && days[i] <= B[k]){
                    dp[i+1][k] = max(dp[i+1][k], dp[i][j] + abs(C[j] - C[k]));
                }
            }
        }
    }
    int ans = 0;
    rep(i,0,N){
        ans = max(ans, dp[D][i]);
    }
    cout << ans << endl;
    return 0;
}