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
    while (true){
        int N,M;
        cin >> N >> M;
        if (N == 0 && M == 0){
            break;
        }
        vector<int> box(M);
        rep(i,0,M){
            cin >> box[i];
        }
        vector<int> x(N);
        rep(i,0,N){
            cin >> x[i];
        } 

        vector<vector<int>> dp(N+1, vector<int>(260, INF));
        dp[0][128] = 0;
        rep(i,0,N){
            rep(j,0,256){
                rep(k,0,M){
                    int base = j + box[k];
                    base = max(base, 0);
                    base = min(base,255);
                    int cost = base - x[i];
                    
                    chmin(dp[i+1][base], dp[i][j] + cost * cost);
                    
                }
            }
        }
        int ans = INF;
        rep(i,0,260) chmin(ans, dp[N][i]);
        cout << ans << endl;
    }
    return 0;
    
}