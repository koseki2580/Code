#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,ll>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)


const int MAX_NUM = 200100;
vector<int> to[MAX_NUM];
vector<ll> cost(MAX_NUM,0);
vector<ll> ans(MAX_NUM,-1);


void DFS(int p = 0){
    stack<P> q;
    q.push({p, cost[p]});
    ans[p] = cost[p];
    while (q.size() > 0){
        P pos_cost = q.top();q.pop();
        for(auto to: to[pos_cost.first]){
            if (ans[to] == -1){
                ans[to] = pos_cost.second + cost[to];
                q.push({to,ans[to]});
            }
        }
    }
}


// void DFS(int now, int p = -1){
//     if (now == 0){
//         ans[now] = cost[now];
//     }else{
//         ans[now] = cost[now] + cost[p];
//         cost[now] += cost[p];
//     }
//     for(auto to: to[now]){
//         if (to != p && ans[to] == -1){
//             DFS(to, now);
//         }
//     }
    
// }
int main() {
    int N,Q;
    cin >> N >> Q;
    rep(i,0,N-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    rep(i,0,Q){
        int p,x;
        cin >> p >> x;
        p--;
        cost[p] += x; 
    }

    DFS(0);

    rep(i,0,N){
        printf("%d ", ans[i]);
    }
    return 0;
}