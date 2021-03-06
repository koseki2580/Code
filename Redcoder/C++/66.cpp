#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
#define rrep(i,nn,n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<double,int>;
using t = tuple<double,int,int>;

#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

double calc2(double x, double y){
    return (x-y) * (x-y);
}

double calc(double x1,double y1,double z1,double x2, double y2, double z2){
    return sqrt(calc2(x1,x2) + calc2(y1,y2) + calc2(z1, z2));
}

int main() {
    while (true){
        int N;
        cin >> N;
        if (N == 0) break;
        vector<double> X(N,0), Y(N,0), Z(N,0), R(N,0);
        rep(i,0,N){
            double x,y,z,r;
            cin >> x >> y >> z >> r;
            X[i] = x;
            Y[i] = y;
            Z[i] = z;
            R[i] = r;
        }
        priority_queue<t, vector<t>, greater<t>> q;
        rep(i,1,N){
            q.push({calc(X[0],Y[0],Z[0],X[i],Y[i],Z[i])- (R[0] + R[i]), 0, i});
        }
        vector<bool> flag(N,false);
        double ans = 0;
        flag[0] = true;
        int count = N-1;
        while (count != 0)
        {
            t a = q.top();q.pop();
            double& dis = get<0>(a);
            int& pos = get<1>(a);
            int& pos2 = get<2>(a);
            if (flag[pos] == true && flag[pos2] == true) continue;
            if (dis > 0){
                ans += dis;
            }
            flag[pos] = true;
            flag[pos2] = true;
            count -= 1;
            rep(i,0,N){
                if (i == pos2) continue;
                if (flag[i] == true) continue;
                q.push({calc(X[pos2],Y[pos2],Z[pos2],X[i],Y[i],Z[i])- (R[pos2] + R[i]), pos2, i});
            }
        }
        

        printf("%.5f\n",ans);
    }
    return 0;
}