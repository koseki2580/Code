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
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        string s, g;
        vector<int> box(24 * 60 * 60 + 5, 0);
        rep(i, 0, n)
        {
            cin >> s >> g;
            int start = (int(s[0] - '0') * 10 + int(s[1] - '0')) * 3600 + (int(s[3] - '0') * 10 + int(s[4] - '0')) * 60 + (int(s[6] - '0') * 10 + int(s[7] - '0'));
            int goal = (int(g[0] - '0') * 10 + int(g[1] - '0')) * 3600 + (int(g[3] - '0') * 10 + int(g[4] - '0')) * 60 + (int(g[6] - '0') * 10 + int(g[7] - '0'));
            ++box[start];
            --box[goal];
            // cout << start << endl;
            // cout << goal << endl;
        }

        vector<int> su(24 * 60 * 60 + 5, 0);
        rep(i, 0, box.size())
        {
            su[i + 1] = su[i] + box[i];
        }
        int ans = 0;
        rep(i, 0, su.size()) chmax(ans, su[i]);
        cout << ans << endl;
    }

    return 0;
}