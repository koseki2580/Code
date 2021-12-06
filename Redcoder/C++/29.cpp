#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int MAX_NUM = 55;
vector<vector<int>> box(MAX_NUM, vector<int>(MAX_NUM, -1));

void BFS(int x, int y){
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    queue<P> q;
    q.push({x,y});
    while (!q.empty()){
        P pos = q.front();q.pop();
        rep(i,0,4){
            int xx = pos.first + dx[i];
            int yy = pos.second + dy[i];

            if (box[xx][yy] == 0){
                box[xx][yy] = box[pos.first][pos.second] + 1;
                q.push({xx,yy});
            }
        }
    }
}

int main() {
    int R,C;
    P s,g;
    cin >> R >> C;
    cin >> s.first >> s.second >> g.first >> g.second;
    rep(i,1,R+1){
        string str;
        cin >> str;
        rep(j,1,C+1){
            if (str[j-1] == '.'){
                box[i][j] = 0;
            }
        }
    }

    BFS(s.first, s.second);
    int ans = box[g.first][g.second];

    cout << ans << endl;
    return 0;
}