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
    vector<vector<bool>> box(N,vector<bool>(N));
    rep(i,0,N)rep(j,0,N){
        box[i][j] = false;
    }
    rep(i,0,M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        box[a][b] = true;
    }
    int ans = 1;
    rep(i,1, 1<<(N)){
        vector<int> con[1];
        rep(j,0,(N)){
            if ((i >> j) & 1 == 1){
                con[0].push_back(j);
            }
        }
        bool flag = true;

        rep(i,0,con[0].size())rep(j,i+1,con[0].size()){
            if (box[con[0][i]][con[0][j]] == false && box[con[0][j]][con[0][i]] == false){
                flag = false;
            }
        }
        
        if (flag == true){
            int b = con[0].size();
            ans = max(ans, b);
        }
    }
    

    cout << ans << endl;
    return 0;
}