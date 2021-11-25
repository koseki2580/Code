#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int N,M;
    cin >> N >> M;
    vector<int> P(N+1,0);
    rep(i,0,N){
        cin >> P[i];
    }
    vector<int> sortP;
    rep(i,0,N+1)rep(j,0,N+1){
        sortP.push_back(P[i] + P[j]);
    }
    sort(sortP.begin(), sortP.end());

    int ans = 0;
    int b = sortP.size();
    rep(i,0,sortP.size()){
        int c = M - sortP[i];
        int pos = lower_bound(sortP.begin(),sortP.end(), c) - sortP.begin() - 1;
        if (sortP[i] + sortP[pos] <= M){
            ans = max(ans, sortP[i] + sortP[pos] );
        }
    }

    cout << ans << endl;
    return 0;
}