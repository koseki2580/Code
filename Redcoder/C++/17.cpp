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
    vector<P> xy(N);
    
    rep(i,0,N){
        cin >> xy[i].first >> xy[i].second;
    }
    vector<int> v(8);
    rep(i,0,8){
        v[i] = i;
    }
    vector<P> ans_xy(8);
    do{
        vector<vector<int>> box(8,vector<int>(8,0));

        bool flag = false;
        // 決められた位置にQがない場合はこれ以上進まない
        rep(i,0,N){
            if (v[xy[i].first] != xy[i].second){
                flag = true;
                break;
            }
        }
        if (flag == true){
            continue;
        }

        bool flag2 = true;
        int x = 0;

        for(auto y: v){
            if (box[x][y] == 1){
                flag2 = false;
                break;
            }
            rep(i,0,8){
                // 縦横を１で埋める
                box[i][y] = 1;
                box[x][i] = 1;
                // 斜めを１で埋める
                if (x - i >= 0 && y - i >= 0){
                    box[x-i][y-i] = 1;
                }
                if (x - i >= 0 && y + i <= 7){
                    box[x-i][y+i] = 1;
                }
                if (x + i <= 7 && y - i >= 0){
                    box[x+i][y-i] = 1;
                }
                if (x + i <= 7 && y + i <= 7){
                    box[x+i][y+i] = 1;
                }
                
            }
            x++;
        }
        if (flag2 == true){
            int xx = 0;
            for(auto y: v){
                
                ans_xy[xx].first = xx;
                ans_xy[xx].second = y;
                xx++;
            }
            break;
        }
    }while (next_permutation(v.begin(), v.end()));
    vector<vector<char>> ans(8,vector<char>(8,'.'));
    rep(i,0,8){
        ans[ans_xy[i].first][ans_xy[i].second] = 'Q';
    }
    rep(i,0,8){
        rep(j,0,8){
            printf("%c",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}