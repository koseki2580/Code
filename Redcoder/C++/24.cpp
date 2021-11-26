#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int MAX_N = 105;
vector<P> ans;
vector<int> box[MAX_N];
int point;
void DFS(int v, int parent = -1){
    ans[v].first = point;
    point++;
    for(auto x:box[v]){
        if (ans[x].first != 0){
            continue;
        }
        DFS(x, v);
    }
    ans[v].second = point;
    point++;
}
int main() {
    int N;
    cin >> N;
    ans = vector<P>(N);
    rep(i,0,N){
        int a,b;
        cin >> a >> b;
        a--;
        rep(j,0,b){
            int x;
            
            cin >> x;
            x--;
            box[i].push_back(x);
        }
    }
    point = 1;
    rep(i,0,N){
        if (ans[i].first == 0){
            DFS(i);
        }
    }
    
    rep(i,0,N){
        printf("%d %d %d\n", i+1,ans[i].first, ans[i].second);
    }

    return 0;
}