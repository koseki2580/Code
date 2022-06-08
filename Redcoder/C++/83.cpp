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
    int N, M;
    cin >> N >> M;
    vector<int> P(M, 0);
    rep(i, 0, M)
    {
        cin >> P[i];
        --P[i];
    }
    vector<int> box(N, 0);
    int now = P[0];
    rep(i, 1, M)
    {
        int a, b;
        a = min(now, P[i]);
        b = max(now, P[i]);
        --box[b];
        ++box[a];
        now = P[i];
    }
    vector<int> s(N + 1, 0);
    rep(i, 0, N)
    {
        s[i + 1] = s[i] + box[i];
    }
    ll ans = 0;
    rep(i, 0, N - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ans += min(1LL * a * s[i + 1], 1LL * b * s[i + 1] + c);
    }

    cout << ans << endl;
    return 0;
}