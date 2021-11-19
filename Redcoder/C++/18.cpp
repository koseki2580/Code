#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i,0,n){
        cin >> s[i];
    }
    int q;
    cin >> q;
    vector<int> t(q);
    rep(i,0,q){
        cin >> t[i];
    }
    int ans = 0;
    rep(i,0,q){
        int l = 0;
        int r = n;
        while (r - l > 1){
            int mid = (r+l)/2;
            if (s[mid] <= t[i]){
                l = mid;
            }else{
                r = mid;
            }
        }
        if (s[l] == t[i]){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}

/**
 * lower_boundを用いた例
 * 
*/
#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i,0,n){
        cin >> s[i];
    }
    int q;
    cin >> q;
    vector<int> t(q);
    rep(i,0,q){
        cin >> t[i];
    }
    int ans = 0;
    rep(i,0,q){
        int num = lower_bound(s.begin(),s.end(), t[i]) - s.begin();
        if (s[num] == t[i]) ans++;
    }

    cout << ans << endl;
    return 0;
}