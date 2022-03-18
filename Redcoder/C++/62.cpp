#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int H,W;
    cin >> H >> W;
    vector<vector<int>> box(10,vector<int>(10,0));
    rep(i,0,10){
        rep(j,0,10){
            cin >> box[i][j];
        } 
    }
    

    rep(k,0,10){
        rep(i,0,10){
            rep(j,0,10){
                chmin(box[i][j], box[i][k] + box[k][j]);
            }
        } 
    }

    int box2[10]{0,0,0,0,0,0,0,0,0,0};
    rep(i,0,H) {
        rep(j,0,W){
            int a;
            cin >> a;
            ++box2[a];
        }
    }
    int ans = 0;
    rep(i,0,10){
        ans += box[i][1] * box2[i];
    }


    cout << ans << endl;
    return 0;
}