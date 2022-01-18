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
    while(true){
        int N;
        cin >> N;
        if (N == 0){
            break;
        }
        vector<int> box(201);
        rep(i,1,201){
            box[i] = i *(i+1) * (i+2) /6;
        }
        vector<int> dp(N+1, INF), odd_dp(N+1, INF);
        dp[0] = 0;
        odd_dp[0] = 0;
        rep(i,1,201){
            rep(j,0,N+1){
                if (box[i] + j <= N){
                    dp[box[i] + j] = min(dp[box[i] + j], dp[j] + 1);
                }else{
                    break;
                }
            }
            if (box[i] % 2 == 1){
                rep(j,0,N+1){
                    if (box[i] + j <= N){
                        odd_dp[box[i] + j] = min(odd_dp[box[i] + j], odd_dp[j] + 1);
                    }else{
                        break;
                    }
                    
                }
                
            }
        }
        

        printf("%d %d\n", dp[N], odd_dp[N]);
    }
    return 0;
}