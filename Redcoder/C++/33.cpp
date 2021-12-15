#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int MAX_NUM = 55;
int H,W;
vector<vector<int>> box(MAX_NUM, vector<int>(MAX_NUM, -1));

int BFS(){
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    queue<P> q;
    q.push({1,1});
    box[1][1] = 1;
    while (!q.empty()){
        P pos = q.front();q.pop();
        rep(i,0,4){
            int y = dy[i] + pos.first;
            int x = dx[i] + pos.second;
            if (box[y][x] == 0){
                box[y][x] = 1 + box[pos.first][pos.second];
                q.push({y,x});
            }
        }
    }
    return box[H][W];
}

int main() {
    int ans;
    cin >> H >> W;
    rep(i,0,H){
        string s;
        cin >> s;
        rep(j,0,W){
            if (s[j] == '.'){
                box[i+1][j+1] = 0;
                ++ans;
            }
        }
    }

    int count = BFS();
    if (count == -1){
        cout << count << endl;
        return 0;
    }
    ans -= count;
    cout << ans << endl;
    return 0;
}