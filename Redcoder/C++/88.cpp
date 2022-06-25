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
    vector<P> box;
    int a;
    cin >> a;
    box.push_back({a, 1});
    rep(i, 0, n - 1)
    {
        int num;
        cin >> num;
        if (i % 2 == 1)
        {
            if (box[box.size() - 1].first == num)
                ++box[box.size() - 1].second;
            else
                box.push_back({num, 1});
        }
        else
        {
            if (box[box.size() - 1].first == num)
                ++box[box.size() - 1].second;
            else
            {
                int count = 1 + box[box.size() - 1].second;
                box.pop_back();
                if (box.size() == 0)
                    box.push_back({num, count});
                else
                    box[box.size() - 1].second += count;
            }
        }
    }
    int ans = 0;
    rep(i, 0, box.size())
    {
        if (box[i].first == 0)
            ans += box[i].second;
    }

    cout << ans << endl;
    return 0;
}