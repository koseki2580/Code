#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {

    int N,M;
    cin >> N >> M;
    vector<int> A[M];
    int p[M];
    rep(i,0,M){
        int k;
        cin >> k;
        rep(j,0,k){
            int a;
            cin >> a;
            A[i].push_back(a);
        }
    }
    rep(i,0,M){
        cin >> p[i];
    }
    int ans = 0;
    rep(i,0,1 << N){
        int n = 0;
    
        rep(j,0,M){
            int con = 0;
            rep(l,0,A[j].size()){
                if (i >> (A[j][l]-1) & 1 == 1){
                    ++con;
                }
            }
            if (con % 2 == p[j]){
                ++n;
            }
        }
        if (n == M){
            ++ans;
        }
    }
    
    cout << ans << endl;
    return 0;
}