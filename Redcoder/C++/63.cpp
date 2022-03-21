#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

int main() {
    int N;
    cin >> N;
    vector<vector<int>> box(N, vector<int>(N,0));
    vector<vector<int>> next(N, vector<int>(N,0));
    rep(i,0,N)rep(j,0,N) cin >> box[i][j];

    // iからjにいくのに必要な経路を記録する
    rep(i,0,N)rep(j,0,N) next[i][j] = j;
    
    rep(k,0,N)rep(i,0,N)rep(j,0,N){
        // i,j,kが全て異なっている際に最小値と一致しているなら
        // iからjにいくためにkを経由しているのでそれを記録する
        if (i != j && i != k && j != k && box[i][j] == box[i][k] + box[k][j]){
            next[i][j] = next[i][k];
        }
        // 最小値を更新できるのでは入力されたグラフは全点間最短距離ではないので-1を出力
        else if(i != j && i != k && j != k && box[i][j] > box[i][k] + box[k][j]){
            cout << -1 << endl;
            return 0;
        }
    }
    
    ll ans = 0;
    // 使用する経路を記録する
    vector<vector<bool>> flag(N,vector<bool>(N,false)) ;
    rep(i,0,N){
        rep(j,i+1,N){
            // iからjまでの最短距離で使用している経路を求める
            int be = i;
            for(int s = i; s != j; s = next[s][j]){
                // すでに経路として記録しているなら答えに加算しない
                if (flag[be][s] == false){
                    flag[be][s] = true;
                    flag[s][be] = true;
                    ans += box[be][s];
                }
                be = s;
            }
            // このループではjに到達する前にループを抜けるので最後にjとの経路を確認する
            if (flag[be][j] == false){
                flag[be][j] = true;
                flag[j][be] = true;
                ans += box[be][j];
            }
        }
    }


    cout << ans << endl;
    return 0;
}