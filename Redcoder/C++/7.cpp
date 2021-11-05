/*
解き方はわかっていたがメモリ問題で全然通らなかった
int 32bit 4byte
bool 1(8)bit 1byte

5000 * 5000 = 25_000_000
int : 25_000_000 * 4 = 100_000_000 95.36743164 Mbyte
bool: 25_000_000 * 1 = 25_000_000  23.84185791 Mbyte

制約が64Mbyteなので
bool型を使わないといけない
メモリがシビアな問題では型によってメモリどれだけかかるか把握して書く必要がある
*/

#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int N;
    cin >> N;

    vector<P> box(N);

    rep(i,0,N){
        cin >> box[i].first >> box[i].second;
    }
    sort(box.begin(), box.end());
    vector<vector<bool>> grid(5005, vector<bool>(5005));
    rep(i,0,N)rep(j,0,N){
        grid[i][j] = false;
    }
    rep(i,0,N){
        grid[box[i].first][box[i].second] = true;
    }
    int ans = 0;
    int X[3] = {1,-1,-1};
    int Y[3] = {-1,1,-1};
    rep(i,0,N){
        rep(j,i+1,N){
            rep(k,0,3){
                int xx = abs(box[i].first - box[j].first) * X[k];
                int yy = abs(box[i].second - box[j].second) * Y[k];
                if (box[i].first + yy < 0 || box[i].second + xx < 0 || box[i].first + yy > 5000 || box[i].second + xx > 5000){
                    continue;
                }
                if (box[j].first + yy < 0 || box[j].second + xx < 0 || box[j].first + yy > 5000 || box[j].second + xx > 5000){
                    continue;
                }
                if (grid[box[i].first + yy][box[i].second + xx] == true && grid[box[j].first + yy][box[j].second + xx] == true){
                    ans = max(ans, (box[i].first - box[j].first)*(box[i].first - box[j].first) + (box[i].second - box[j].second)*(box[i].second - box[j].second));
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
