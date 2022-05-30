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
    int H, W, K;
    ll V;
    cin >> H >> W >> K >> V;

    vector<vector<ll>> box(H + 1, vector<ll>(W + 1, 0));
    rep(i, 0, H) rep(j, 0, W) cin >> box[i + 1][j + 1];
    rep(i, 1, H + 1) rep(j, 0, W)
    {
        box[i][j + 1] += box[i][j];
    }
    rep(i, 0, H) rep(j, 1, W + 1)
    {
        box[i + 1][j] += box[i][j];
    }
    int ans = 0;
    rep(i, 0, H) rep(j, 0, W) rep(gi, i + 1, H + 1) rep(gj, j + 1, W + 1)
    {
        int m = (gi - i) * (gj - j);
        ll cost = box[gi][gj] - box[i][gj] - box[gi][j] + box[i][j] + 1LL * K * m;
        if (cost <= V)
            chmax(ans, m);
    }

    cout << ans << endl;
    return 0;
}