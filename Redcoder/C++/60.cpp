#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const ll INF = 100100100100100;

int main() {
    int V,E;
    cin >> V >> E;
    vector<vector<ll>> box(V,vector<ll>(V,INF));
    rep(i,0,E){
        int s,t,d;
        cin >> s >> t >> d;
        box[s][t] = d;
    }
    rep(i,0,V){
        box[i][i] = 0;
    }
    rep(k,0,V){
        rep(i,0,V){
            rep(j,0,V){
                box[i][j] = min(box[i][j], box[i][k] + box[k][j]);
            }
        }
    }
    rep(i,0,V){
        if  (box[i][i] < 0){
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    rep(i,0,V){
        rep(j,0,V){
            if (j == V-1){
                if (box[i][j] >= INF/2){
                    printf("INF");
                }else{
                    printf("%d",box[i][j]);
                }
            }else{
                if (box[i][j] >= INF/2){
                    printf("INF ");
                }else{
                    printf("%lld ",box[i][j]);
                }
            }
        }
        printf("\n");
    }

    return 0;
}