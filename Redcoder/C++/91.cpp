#include <bits/stdc++.h>
#define rep(i, nn, n) for (int i = nn; i < (n); ++i)
#define rrep(i, nn, n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main()
{
    double a, b, x;
    cin >> a >> b >> x;
    double check = a * a * b / 2;
    if (x == check)
    {
        printf("%.10f\n", 45.0);
    }
    else if (x < check)
    {
        double z = 2 * x / b / a;
        double rad = atan2(z, b);
        double deg = 90 - rad * (180 / M_PI);
        printf("%.10f\n", deg);
    }
    else
    {
        double z = 2 * b - 2 * x / a / a;
        double rad = atan2(a, z);
        double deg = 90 - rad * (180 / M_PI);
        printf("%.10f\n", deg);
    }
    return 0;
}