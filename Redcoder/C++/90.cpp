#include <bits/stdc++.h>
#define rep(i, nn, n) for (int i = nn; i < (n); ++i)
#define rrep(i, nn, n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int N, M;
vector<vector<int>> box(105, vector<int>(3, 0));
vector<P> con(105);

bool check(double mid)
{
    rep(i, 0, M)
    {
        rep(j, 0, N)
        {
            double x = con[i].first - box[j][0];
            double y = con[i].second - box[j][1];
            double dist = sqrt(x * x + y * y);
            if (dist < mid + box[j][2])
                return false;
        }
        rep(j, 0, M)
        {
            if (i == j)
                continue;
            double x = con[i].first - con[j].first;
            double y = con[i].second - con[j].second;
            double dist = sqrt(x * x + y * y);
            if (dist < mid + mid)
                return false;
        }
    }
    return true;
}
int main()
{

    cin >> N >> M;

    rep(i, 0, N)
    {
        cin >> box[i][0] >> box[i][1] >> box[i][2];
    }

    rep(i, 0, M)
    {
        cin >> con[i].first >> con[i].second;
    }
    double l = 0;
    double r = 1001001000;
    while ((r - l) > 0.0000000001)
    {
        double mid = (l + r) / 2;
        if (check(mid) == true)
            l = mid;
        else
            r = mid;
    }
    if (l == 1001001000)
    {
        rep(i, 0, N)
        {
            chmin(l, 1.0 * box[i][2]);
        }
    }

    printf("%.10f\n", l);
    return 0;
}