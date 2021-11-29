#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int DFS(int x, int y,int count, vector<vector<int>> aa){
    int num = 0;
    rep(i,0,4){
        int xx = x+dx[i];
        int yy = y+dy[i];
        if (aa[xx][yy] == 1){
            aa[xx][yy] = 0;
            num = max(num,DFS(xx,yy,count+1,aa));
            aa[xx][yy] = 1;
        }
    }
    return max(num, count);
}

int main() {
    int w,h;
    cin >> w >> h;
    vector<vector<int>> box(h+2, vector<int>(w+2,0));
    rep(i,0,h)rep(j,0,w){
        cin >> box[i+1][j+1];
    }
    int ans = 0;
    
    rep(i,0,h)rep(j,0,w){
        if (box[i+1][j+1] == 1){
            ans = max(ans, DFS(i+1,j+1,0,box));
        }
    }

    cout << ans << endl;
    return 0;
}