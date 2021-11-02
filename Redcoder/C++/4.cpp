#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

int N,M;
ll A[100][100];

int main() {
    cin >> N >>M;
    rep(i,0,N)rep(j,0,M){
        cin >> A[i][j];
    }
    ll ans = 0;
    rep(i,0,N)rep(j,i+1,M){
        ll count = 0;
        rep(k,0,N){
            count += max(A[k][j],A[k][i]);
        }
        ans = max(ans,count);
    }

    cout << ans << endl;
    return 0;
}