#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

int H,W,N;
int BFS(P st, P go, vector<vector<int>> bb){
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    queue<P> q;
    q.push(st);
    while (!q.empty()){
        P pos = q.front();q.pop();
        rep(i,0,4){
            int x = pos.first + dx[i];
            int y = pos.second + dy[i];
            if (bb[x][y] == 0){
                bb[x][y] = bb[pos.first][pos.second] + 1;
                q.push({x,y});
            }
        }
        if (bb[go.first][go.second] != 0){
            break;
        }
    }
    return bb[go.first][go.second];
}

int main() {
    
    cin >> H >> W >> N;
    vector<vector<int>> box(H+2, vector<int>(W+2,-1));
    vector<P> pos(N+1);
    int n =0;
    rep(i,0,H){
        string a;
        cin >> a;
        rep(j,0,W){
            if (a[j] == 'S'){
                box[i+1][j+1] = 0;
                pos[0].first = i+1;
                pos[0].second = j+1;
            }else if(a[j] != '.' && a[j] != 'X'){
                box[i+1][j+1] = 0;
                int index = a[j] - '0';
                pos[index].first = i+1;
                pos[index].second = j+1;
            }else if (a[j] == '.'){
                box[i+1][j+1] = 0;
            }
        }
    }
   
    int ans = 0;
    rep(i,0,N){
        
        ans += BFS(pos[i],pos[i+1],box);
    }

    cout << ans << endl;
    return 0;
}