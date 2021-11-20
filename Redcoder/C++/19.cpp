#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int d,n,m;
    cin >> d >> n >> m;
    vector<int> shop(n+1,0);
    rep(i,0,n-1){
        cin >> shop[i+1];
    }
    shop[n] = d;
    sort(shop.begin(), shop.end());
    int ans = 0;
    rep(i,0,m){
        int order;
        cin >> order;
        int pos = lower_bound(shop.begin(),shop.end(), order) - shop.begin();
        ans += min(abs(order - shop[pos]),abs(order - shop[pos-1]));
    }


    cout << ans << endl;
    return 0;
}