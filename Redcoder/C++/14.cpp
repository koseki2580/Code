#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const ll inf = 100100100100100;


int main() {
    int N,K;
    cin >> N >> K;

    vector<int> a(N,0);
    rep(i,0,N){
        cin >>a[i];
    }
    reverse(a.begin(), a.end());
    ll ans = inf;
    rep(i,0, 1 << (N-1)){
        ll high = a[N-1];
        int count = 1;
        ll cost = 0;
        if (i == (1 << (N-1))-1){
            int x = 0;
        }
        rrep(j,N-2,-1){
            if (i >> j & 1 == 1){
                if (high >= a[j]){
                    high = high + 1;
                    cost += high - a[j];
                }else{
                    high = a[j];
                }
                count++;
            }else{
                if (high < a[j]){
                    count++;
                    high = a[j];
                }
            }
        }

        if (count >= K){
            ans = min(ans,cost);
        }
    }

    cout << ans << endl;
    return 0;
}