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
    int n;
    cin >> n;
    vector<int>
        box(10000005, 0);
    rep(i, 0, n)
    {
        int a, b;
        cin >> a >> b;
        ++box[a];
        --box[b + 1];
    }
    vector<int> s(box.size() + 1, 0);
    rep(i, 0, box.size())
    {
        s[i + 1] = s[i] + box[i];
    }
    int ans = 0;
    rep(i, 0, s.size()) chmax(ans, s[i]);

    cout << ans << endl;
    return 0;
}