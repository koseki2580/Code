#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int N;
    cin >> N;

    vector<pair<ll,ll>> box(N);
    vector<ll> ins(N);
    vector<ll> outs(N);
    rep(i,0,N){
        cin >> box[i].first >> box[i].second;
        ins[i] = box[i].first;
        outs[i] = box[i].second;
    }
    sort(ins.begin(), ins.end());
    sort(outs.begin(), outs.end());
    ll in = ins[N/2];
    ll out = outs[N/2];
    
    ll ans = 0;
    rep(i,0,N){
        ans += abs(box[i].first - in);
        ans += abs(box[i].second - box[i].first);
        ans += abs(out - box[i].second);
    }
    cout << ans << endl;
    return 0;
}