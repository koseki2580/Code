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
    vector<int> A(N),B(N),C(N);
    rep(i,0,N){
        cin >> A[i];
    }
    rep(i,0,N){
        cin >> B[i];
    }
    rep(i,0,N){
        cin >> C[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    ll ans =0;
    rep(i,0,N){
        int pos = lower_bound(A.begin(),A.end(), B[i]) - A.begin();
        int pos2 = C.end() - upper_bound(C.begin(), C.end(), B[i]) ;
        ans += (ll)pos * pos2;
    }
    cout << ans << endl;
    return 0;
}