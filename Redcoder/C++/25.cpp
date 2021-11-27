#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int dx[8]{0,1,0,-1,1,1,-1,-1};
    int dy[8]{1,0,-1,0,1,-1,1,-1};
    while (true) {
        int w,h;
        cin >> w >> h;
        if (w == 0 && h == 0){
            break;
        }
        vector<vector<int>> box(h+2,vector<int>(w+2,-1));
        rep(i,0,h)rep(j,0,w){
            int a;
            cin >> a;
            if (a == 1){
                box[i+1][j+1] = 0;
            }
        }
        
        int ans = 0;
        rep(i,0,h)rep(j,0,w){
            if (box[i+1][j+1] == 0){
                ans++;
                stack<P> q;
                q.push({i+1,j+1});
                while (q.size() > 0){
                    P pos = q.top();q.pop();
                    rep(k,0,8){
                        int x = pos.first + dx[k];
                        int y = pos.second + dy[k];
                        if (box[x][y] == 0){
                            box[x][y] = ans;
                            q.push({x,y});
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}