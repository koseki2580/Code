#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

int BFS(int y, int x, vector<vector<int>> box){

    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    queue<P> q;
    q.push({1,1});
    box[1][1] = 1;
    while (!q.empty()){
        P pos = q.front();q.pop();
        rep(i,0,4){
            int X = dx[i] + pos.second;
            int Y = dy[i] + pos.first;
            if (box[Y][X] == 0 && box[Y+dy[i]][X+dx[i]] == 0){
                box[Y+dy[i]][X+dx[i]] = box[pos.first][pos.second] + 1;
                int dY = Y + dy[i];
                int dX = X + dx[i];
                q.push({dY,dX});
            }
        }
    }
    rep(i,0,box.size()){
        rep(j,0,box[i].size()){
            printf("%d ",box[i][j]);
        }
        printf("\n");
    }
    return box[y*2-1][x*2-1];
}


int main() {
    while (true){
        int w,h;
        cin >> w >> h;
        if (w == 0 && h == 0){
            break;
        }
        vector<vector<int>> box((h+1)+h, vector<int> ((w+1)+w,0));
        rep(i,0,box.size()){
            box[i][0] = -1;
            box[i][box[i].size()-1] = -1;
        }
        rep(i,0,box[0].size()){
            box[0][i] = -1;
            box[box.size()-1][i] = -1;
        }
        rep(i,1,h*2){
            if (i % 2 == 1){
                rep(j,1,w){
                    int n;
                    cin >> n;
                    box[i][2*j] = n;
                }
            }else{
                rep(j,1,w+1){
                    int n;
                    cin >> n;
                    box[i][2*j-1] = n;
                }
            }
        }
        // rep(i,0,box.size()){
        //     rep(j,0,box[i].size()){
        //         printf("%d ",box[i][j]);
        //     }
        //     printf("\n");
        // }
        int ans = BFS(h,w,box);

        cout << ans << endl;


    }
    


    return 0;
}