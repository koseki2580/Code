#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    vector<int> q(N);
    rep(i,0,N){
        cin >> p[i];
    }
    rep(i,0,N){
        cin >> q[i];
    }
    vector<int> v(N);
    rep(i,0,N){
        v[i] = i+1;
    }
    bool flag1 = false;
    bool flag2 = false;
    int n = 0;
    int n2 = 0;
    int count = 1;
    do{
        if (n != 0 && n2 != 0){
            break;
        }
        bool flag1 = true;
        bool flag2 = true;
        rep(i,0,N){
            if (v[i] == p[i]){
                continue;
            }else{
                flag1 = false;
                break;
            }
        }
        if (flag1 == true){
            n = count;
        }
        rep(i,0,N){
            if (v[i] == q[i]){
                continue;
            }else{
                flag2 = false;
                break;
            }
        }
        if (flag2 == true){
            n2 = count;
        }

        count++;
        
    }while (next_permutation(v.begin(), v.end()));

    cout << abs(n-n2) << endl;
    return 0;
}