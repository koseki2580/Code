#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

/**
* 
* 素因数分解
* O(√N)
* 
*/
vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0; // 指数
        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        // その結果を push
        res.push_back({a, ex});
    }
    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a = prime_factorize(n);
    string ss = to_string(n) + ":";
    rep(i,0,a.size()){
        pair<ll,ll> b = a[i];
        // printf("%ld, %ld ", b.first, b.second);
        rep(j,0,b.second) {
            ss += " ";
            ss += to_string(b.first);
        }
        // printf("%s,",to_string(b.first));
        
    }
    cout << ss << endl;

    return 0;
}