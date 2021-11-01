#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    string s;
    cin >> s;
    int ans = 0;
    int count = 0;
    for (int i = 0; i <s.length(); ++i) {
        if (s[i] == 'A'){
            count++;
        }
        else if (s[i] == 'C'){
            count++;    
        }
        else if (s[i] == 'G'){
            count++;
        }
        else if (s[i] == 'T'){
            count++;
        }
        else{
            ans = max(ans,count);
            count = 0;
        }
    }
    ans = max(ans,count);
    cout << ans << endl;
    return 0;
}