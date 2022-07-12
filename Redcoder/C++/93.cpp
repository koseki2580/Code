#include <bits/stdc++.h>
#define rep(i, nn, n) for (int i = nn; i < (n); ++i)
#define rrep(i, nn, n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int H, W, K;
int remove_block(vector<int> &box)
{
    vector<P> con;
    con.push_back({box[0], 1});
    rep(i, 1, W)
    {
        if (con[con.size() - 1].first == box[i])
            ++con[con.size() - 1].second;
        else
            con.push_back({box[i], 1});
    }
    int count = 0;
    int n = 0;
    rep(i, 0, con.size())
    {
        if (con[i].second >= K)
        {
            count += con[i].first * con[i].second;
            rep(j, n, n + con[i].second)
            {
                box[j] = 0;
            }
            // break;
        }
        n += con[i].second;
    }

    return count;
}
int add_point(vector<vector<int>> &box)
{
    int count = 0;
    rep(i, 0, box.size())
    {
        count += remove_block(box[i]);
    }

    return count;
}

void down_block(vector<vector<int>> &box)
{
    int n = box.size();
    rep(i, 0, W)
    {
        stack<int> con;
        rep(j, 0, n)
        {
            if (box[j][i] != 0)
            {
                con.push(box[j][i]);
            }
        }
        int m = n - 1;
        while (!con.empty())
        {
            box[m][i] = con.top();
            con.pop();
            --m;
        }
        while (m >= 0)
        {
            box[m][i] = 0;
            --m;
        }
    }
}

int main()
{
    cin >> H >> W >> K;
    vector<vector<int>> box(H, vector<int>(W, 0));
    rep(i, 0, H)
    {
        string s;
        cin >> s;
        rep(j, 0, W)
        {
            box[i][j] = int(s[j]) - '0';
        }
    }
    ll ans = 0;
    rep(i, 0, H) rep(j, 0, W)
    {
        vector<vector<int>> box2;
        copy(box.begin(), box.end(), back_inserter(box2));
        box2[i][j] = 0;

        down_block(box2);
        // printf("\n");
        // rep(i, 0, H)
        // {
        //     rep(j, 0, W)
        //     {
        //         printf("%d ", box2[i][j]);
        //     }
        //     printf("\n");
        // }

        int n = 0;
        ll num = 0;
        while (true)
        {
            int count = add_point(box2);
            num += 1LL * count * (1 << n);
            if (count == 0)
                break;

            // 石を下に移動処理
            down_block(box2);
            ++n;
        }
        ans = max(ans, num);
    }

    cout << ans << endl;
    return 0;
}