#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int N,M;
    cin >> N >> M;

    vector<vector<int>> box(N,vector<int>(M));
    rep(i,0,N)rep(j,0,M){
        cin >> box[i][j];
    }
    int ans =0;
    rep(i,0,1 << N){
        vector<int> con(N,0);
        rep(j,0,N){
            if (i >> j & 1 == 1){
                con[j] = 1;
            } 
        }
        int n = 0;
        rep(j,0,M){
            int count = 0;
            rep(k,0,N){
                count += (box[k][j] + con[k]) % 2;
            }
            n += max(count, N - count);
        }
        ans = max(ans,n);
    }

    cout << ans << endl;
    return 0;
}