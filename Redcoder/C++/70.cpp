#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int mod = 1000000007;
ll calc(ll m,ll n, int mod){
    ll ret = 1;
    ll temp = m;
    while (n > 0){
        if (n & 1 == 1){
            ret *= temp;
            ret %= mod;
        }
        temp *= temp;
        temp %= mod;
        n >>=1;
    }
    return ret;
}

int main() {
    int m,n;
    cin >> m >> n;
    ll ans = calc(m,n,mod);

    cout << ans << endl;
    return 0;
}