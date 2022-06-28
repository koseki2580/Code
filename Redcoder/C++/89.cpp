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
    int N;
    cin >> N;

    vector<P> box;
    int a;
    cin >> a;
    box.push_back({a, 1});
    rep(i, 0, N - 1)
    {
        int b;
        cin >> b;
        if (box[box.size() - 1].first == b)
        {
            box.push_back({b, 1});
        }
        else
        {
            box[box.size() - 1].first = b;
            ++box[box.size() - 1].second;
        }
    }
    int ans = 0;
    if (box.size() < 3)
    {
        ans = N;
    }
    else
    {
        rep(i, 1, box.size() - 1)
        {
            chmax(ans, box[i - 1].second + box[i].second + box[i + 1].second);
        }
    }

    cout << ans << endl;
    return 0;
}