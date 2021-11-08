#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {

    int n;
    cin >> n;
    int A[n];
    rep(i,0,n){
        cin >> A[i];
    }
    int m;
    cin >> m;
    int q[m];
    rep(i,0,m){
        cin >> q[i];
    }
    // C++だから間に合ったがPythonでも間に合うように書くことも可能である。
    rep(i,0,m){
        int check = q[i];
        bool flag = false;
        rep(j, 0, 1 << n){
            int count = 0;
            rep(k,0,n){
                if ((j >> k) & 1 == 1) {
                    count += A[k];
                }
            }
            if (count == check){
                flag = true;
                break;
            }
        }
        if(flag == true){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
    return 0;
}