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
    vector<int> v(N);
    rep(i,0,N){
        v[i] = i;
    }
    double ans= 0.0;
    int count = 0;
    do{

        count++;
        bool flag = true;
        int xx,yy ;
        for(auto x : v){
            if (flag != true){
                ll X = (xx - xy[x].first);
                ll Y = (yy - xy[x].second);
                ans += sqrt( X*X + Y*Y);
                xx = xy[x].first;
                yy = xy[x].second;
            }
            else{
                xx = xy[x].first;
                yy = xy[x].second;
                flag = false;
            }
        }
    }while (next_permutation(v.begin(), v.end()));

    printf("%.8f\n", ans/count);
    return 0;
}