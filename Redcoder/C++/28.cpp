#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int MAX_NUM = 105;

vector<int> box[MAX_NUM];
vector<int> ans(MAX_NUM,-1);

void BFS(){
    ans[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()){
        int pos = q.front();q.pop();
        for (auto to: box[pos]){
            if (ans[to] == -1){
                ans[to] = ans[pos] + 1;
                q.push(to);
            }
        }
    }
}

int main() {
    int N;

    cin >> N;
    rep(i,0,N){
        int a,b;
        cin >> a >> b;
        a--;
        rep(j,0,b){
            int c;
            cin >> c;
            c--;
            box[a].push_back(c);
        }

    }
    BFS();
    rep(i,0,N){
        printf("%d %d\n",i+1, ans[i]);
    }
    return 0;
}