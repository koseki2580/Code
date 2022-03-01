#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1001001001;
vector<P> box[105];

int dik(int s, int g){
    vector<int> costs(105,INF);
    costs[s] = 0;
    priority_queue< P, vector<P>, greater<P> > q;
    for(auto x:box[s]){
        q.push(x);
    }
    while (!q.empty()){
        P a = q.top();q.pop();
        int pos = a.first;
        int cost = a.second;
        if (costs[pos] < cost){
            continue;
        }
        costs[pos] = cost;
        for(auto b:box[pos]){
            int to = b.first;
            int cost2 = b.second;
            if (costs[to] > cost + cost2){
                costs[to] = cost + cost2;
                q.push({to, costs[to]});
            }
        }
    }
    return costs[g];
}

int main() {
    int n,k;
    cin >> n >> k;
    rep(i,0,k){
        int a;
        cin >> a;
        if (a == 1){
            int s,t,c;
            cin >> s >> t >> c;
            --s;--t;
            box[s].push_back({t,c});
            box[t].push_back({s,c});
        }else{
            int s,t;
            cin >> s >> t;
            --s;--t;
            int cost = dik(s,t);
            if (cost == INF){
                cout << -1 << endl;
            }else{
                cout << cost << endl;
            }
        }
    }




    return 0;
}