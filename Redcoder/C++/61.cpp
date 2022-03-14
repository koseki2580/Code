#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1001001001;

int main() {

    int N,M;
    cin >> N >> M;
    vector<vector<int>> box(N, vector<int>(N,INF));
    rep(i,0,M){
        int a,b,t;
        cin >> a >> b >> t;
        --a; --b;
        box[a][b] = t;
        box[b][a] = t;
    }
    rep(i,0,N){
        box[i][i] = 0;
    }
    rep(k,0,N){
        rep(i,0,N){
            rep(j,0,N){
                box[i][j] = min(box[i][j], box[i][k] + box[k][j]);
            }
        }
    }
    int ans = INF;
    rep(i,0,N){
        int maxnum = 0;
        rep(j,0,N){
            chmax(maxnum, box[i][j]);
        }
        chmin(ans, maxnum);
    }
    cout << ans << endl;
    return 0;
}