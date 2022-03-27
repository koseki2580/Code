#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int N,M,K;
    cin >> N >> M >> K;
    vector<vector<P>> box(N);
    rep(i,0,M){
        int a,b,c;
        cin >> a >> b >> c;
        --a; --b;
        // P aa,bb;
        // aa.first = b;
        // aa.second = c;
        // bb.first = a;
        // bb.second = c;
        box[a].emplace_back(b,c);
        box[b].emplace_back(a,c);
    }
    priority_queue<P, vector<P>, greater<P>> q;
    vector<bool> check(N,false);
    int count = N-1;
    for (auto x:box[0]){
        q.push({x.second, x.first});
    }
    check[0] = true;
    vector<int> costs;
    int ans =0;
    while (count > 0){
        P a = q.top();q.pop();
        int cost = a.first;
        int pos = a.second;
        if (check[pos] == true){
            continue;
        }
        --count;
        ans += cost;
        costs.emplace_back(cost);
        check[pos] = true;
        for (auto to:box[pos]){
            if (check[to.first] == false){
                q.push({to.second, to.first});
            }
        }
    }
    sort(costs.begin(), costs.end(), greater<int>());
    rep(i,0,K-1){
        ans -= costs[i];
    }



    cout << ans << endl;
    return 0;
}