#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

int n,m;
int main() {
    while (true) {
        int ans = 0;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        rep(i,1,n+1)rep(j,i+1,n+1)rep(k,j+1,n+1){
            if (i+j+k == m){
                ans += 1;
            }
        }
        cout << ans << endl;

    }


    return 0;
}