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
    vector<P> grid(N);
    rep(i,0,N){
        cin >> grid[i].first >> grid[i].second;
    }
    int M;
    cin >> M;
    vector<P> box(M);
    rep(i,0,M){
        cin >> box[i].first >> box[i].second;
    }
    map<P,bool> con;
    rep(i,0,M){
        con[box[i]] = true;
    }
    P ans;
    rep(i,0,M){
        bool check = true;
        ans.first = box[i].first - grid[0].first ;
        ans.second = box[i].second - grid[0].second;
        rep(j,0,N){
            P cc = {ans.first + grid[j].first, ans.second + grid[j].second};
            if (con[cc] != true){
                check = false;
                break;
            }
        }
        if (check == true){
            int v = 1;
            break;
        }
    }

    printf("%d %d\n",ans.first, ans.second);
    return 0;
}