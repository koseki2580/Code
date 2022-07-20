#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    ll A,B,K;
    cin >> A >> B >> K;
    if (A >=K) {
        A -= K;
        K = 0;
    }
    else{
        K -= A;
        A = 0;
    }
    if (B >=K) B -= K;
    else{
        K -= B;
        B = 0;
    }


    printf("%lld %lld\n", A,B);
    return 0;
}