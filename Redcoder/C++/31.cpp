#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int MAX_NUM = 105;
int ans = 0;
vector<vector<int>> box(MAX_NUM, vector<int>(MAX_NUM, 0));

void BFS(){
    queue<P> q;
    q.push({1,1});
    box[1][1] = -1;
    

    

    while (!q.empty()){
        P pos = q.front();q.pop();
        if (pos.first % 2 == 0){
            int dx[6] = {0, 1, 1, 1, 0, -1};
            int dy[6] = {-1, -1, 0, 1, 1, 0};
            rep(i,0,6){
                int y = pos.first + dy[i];
                int x = pos.second + dx[i];
                if (box[y][x] == 1){
                    ans++;
                }else if (box[y][x] == 0){
                    box[y][x] = -1;
                    q.push({y,x});
                }
            }
        }else{
            int dx[6] = {-1, 0, 1, 0, -1, -1};
            int dy[6] = {-1, -1, 0, 1, 1, 0};
            rep(i,0,6){
                int y = pos.first + dy[i];
                int x = pos.second + dx[i];
                if (box[y][x] == 1){
                    ans++;
                }else if (box[y][x] == 0){
                    box[y][x] = -1;
                    q.push({y,x});
                }
            }
        }
        

    }
}
int main() {
    int H,W;
    cin >> W >> H;

    rep(i,0,H){
        rep(j,0,W){
            cin >> box[i+2][j+2];
        }
    }
    rep(i,0,MAX_NUM){
        box[0][i] = -1;
        box[104][i] = -1;
    }
    rep(i,0,MAX_NUM){
        box[i][0] = -1;
        box[i][104] = -1;
    }

    BFS();


    cout << ans << endl;
    return 0;
}