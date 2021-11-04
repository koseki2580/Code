#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {

    int N;
    string S;
    cin >> N >> S;
    string a;
    int ans = 0;
    rep(i,0,1000){
        if (i < 10){
            a = "00" + to_string(i);
        }
        else if (i < 100){
            a = "0" + to_string(i);
        }
        else{
            a = to_string(i);
        }
        int count = 0;
        rep(j,0,N){
            if (a[count] == S[j]){
                count++;
                if (count ==3){
                    ans++;
                    break;
                }
            }
        }

    }
    cout << ans << endl;
    return 0;
}