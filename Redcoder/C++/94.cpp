#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {

    while (true){
        int n,w,d;
        cin >> n >> w >> d;
        if (n == 0 && w == 0 && d == 0) break;
        vector<P> box;
        box.push_back({w,d});
        rep(i,0,n){
            int p,s;
            cin >> p >> s;
            --p;
            P delpiece = box[p];
            box.erase(box.begin() + p);
            int x = delpiece.first;
            int y = delpiece.second;
            s += 2*x + 2*y;
            s %= (2*x + 2*y);
            P a,b;
            // 上
            if (s < x){
                a.second = y;
                b.second = y;
                a.first = min(s, x-s);
                b.first = max(s,x-s);
            }
            // 右
            else if (s < x+y){
                s -= x;
                a.first = x;
                b.first = x;
                a.second = min(s, y-s);
                b.second = max(s,y-s);
            }
            // 下
            else if (s < 2 * x + y){
                s-= x+y;
                a.second = y;
                b.second = y;
                a.first = min(s, x-s);
                b.first = max(s,x-s);
            }
            // 左
            else {
                s -= x+x+y;
                a.first = x;
                b.first = x;
                a.second = min(s, y-s);
                b.second = max(s,y-s);
            }
            // printf("%d %d\n",a.first,a.second);
            // printf("%d %d\n",b.first,b.second);
            box.push_back(a);
            box.push_back(b);
        }
        vector<int> ans;
        rep(i,0,box.size()){
            ans.push_back(box[i].second * box[i].first);
        }

        sort(ans.begin(), ans.end());
        rep(i,0,ans.size()){
            if (i == ans.size()-1) printf("%d",ans[i]);
            else printf("%d ",ans[i]);
        }
        printf("\n");
    }
    


    return 0;
}