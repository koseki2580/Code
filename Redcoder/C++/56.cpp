#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1001001001;

int main() {
    int V,E,r;
    cin >> V >> E >> r;
    vector<P> box[V];
    rep(i,0,E){
        int s,t,d;
        cin >> s >> t >> d;
        box[s].push_back({t,d});
    }

    priority_queue< P, vector<P>, greater<P> > q;
    vector<int> ans(V,INF);

    rep(i,0,box[r].size()){
        q.push(box[r][i]);
    }
    ans[r] = 0;
    while (!q.empty()){
        P a = q.top(); q.pop();
        int pos = a.first;
        int cost = a.second;
        if (ans[pos] < cost){
            continue;
        }
        ans[pos] = cost;
        for (auto b: box[pos]){
            int to = b.first;
            int to_cost = b.second;
            if (cost + to_cost < ans[to]){
                ans[to] = cost + to_cost;
                q.push({to, cost + to_cost});
            }
        }
    }


    rep(i,0,V){
        if (ans[i] == INF){
            cout << "INF" << endl;
        }
        else{
            cout << ans[i] << endl;
        }
    }
    return 0;
}