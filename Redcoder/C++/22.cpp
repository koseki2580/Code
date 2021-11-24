#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)


double p;
double check(double num){
    return num +  p / pow(2,(2 * num/3));
}


int main() {
    cin >> p;
    double l,r;
    l = 0;
    r = 100100100100100100;
    while (r - l > 0.0000001){
        double c1 = l + (r-l)/3;
        double c2 = r - (r-l)/3;
        if (check(c1) < check(c2)){
            r = c2;
        }else{
            l = c1;
        }

    }

    printf("%.10f\n", check(l));
    return 0;
}