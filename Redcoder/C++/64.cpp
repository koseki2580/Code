#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int V,E;
    cin >> V >> E;
    // vector<vector<int>> box(N, vector<int>(N,0));
    vector<P> box[V];
    rep(i,0,E){
        int s,t,w;
        cin >> s >> t >> w;
        P a;
        P b;
        a.first = t;
        b.first = s;
        a.second = w;
        b.second = w;
        box[s].emplace_back(a);
        box[t].emplace_back(b);
    }
    int ans = 0;
    vector<bool> flag(V,false);
    priority_queue<P, vector<P>, greater<P> > q;
    for(auto x:box[0]){
        q.push({x.second,x.first});
    }
    flag[0] = true;
    int count = V-1;
    while (count != 0)
    {
        P a = q.top();q.pop();
        int pos = a.second;
        int cost = a.first;
        if (flag[pos] == true){
            continue;
        }
        flag[pos] = true;
        ans += cost;
        --count;
        for(auto to:box[pos]){
            if (flag[to.first] == false){
                q.push({to.second, to.first});
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}