#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int mod = 1000000007;
struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

mint modpow(mint n, int m){
    mint ret = 1;
    while (m > 0)
    {
        if (m & 1 == 1){
            ret *= n;
        }
        n *= n;
        m >>=1;
    }
    return ret;
    
}

int main() {
    int n,q;
    cin >> n >> q;
    vector<int> a(n), c(q+1);
    rep(i,0,n) cin >> a[i];
    rep(i,0,q) {
        cin >> c[i];
        --c[i];
    }
    c[q] = 0;
    vector<mint> box(n-1);
    rep(i,1,n){
        box[i-1] = modpow((mint)a[i-1],a[i]);
    }
    vector<mint> s(n);
    s[0] = 0;
    rep(i,0,box.size()){
        s[i+1] = s[i] + box[i];
    }
    mint ans = 0;
    int start = 0;
    rep(i,0,q+1){
        int next = c[i];
        if (start > c[i]){
            swap(start, next);
        }

        ans += s[next] - s[start];
        start = c[i];
    }


    cout << ans << endl;
    return 0;
}