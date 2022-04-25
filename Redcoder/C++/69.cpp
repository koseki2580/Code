#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

vector<bool> calc(int n){
    vector<bool> ret(n, true);
    ret[1] = false;
    ret[0] = false;
    rep(i,2,n){
        if (ret[i] == false) continue;
        for(int j = i+i; j < n; j += i){
            ret[j] = false;
        }
    }
    return ret;
}

int main() {
    int q;
    cin >> q;
    int n = 100005;
    vector<bool> b = calc(n);
    vector<int> c(n,0);
    rep(i,0,n){
        if (b[i] == true && b[(i +1)/2] == true) c[i] = 1;
    }
    // rep(i,0,10){
    //     printf(b[i] ? "true " : "false ");
    // }

    vector<int> s(n+1,0);
    rep(i,1,n+1){
        s[i] = s[i-1] + c[i-1];
    }
    // rep(i,0,15){
    //     printf("%d ", s[i]);
    // }

    rep(i,0,q){
        int l,r;
        cin >> l >> r;
        cout << s[r+1] - s[l] << endl;
    }
    return 0;
}