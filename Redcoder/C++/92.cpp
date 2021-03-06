#include <bits/stdc++.h>
#define rep(i, nn, n) for (int i = nn; i < (n); ++i)
#define rrep(i, nn, n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int remove_block(vector<int> &box)
{
    vector<P> con;
    con.push_back({box[0], 1});
    rep(i, 1, 5)
    {
        if (con[con.size() - 1].first == box[i])
            ++con[con.size() - 1].second;
        else
            con.push_back({box[i], 1});
    }
    int count = 0;
    int cha = 0;
    int n = 0;
    rep(i, 0, con.size())
    {
        if (con[i].second >= 3)
        {
            count = con[i].first * con[i].second;
            cha = con[i].first;
            rep(j, n, n + con[i].second)
            {
                box[j] = 0;
            }
            break;
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
    rep(i, 0, 5)
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
    // ifstream in("redcoder/input.txt");
    // cin.rdbuf(in.rdbuf());
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<vector<int>> box(n, vector<int>(5, 0));
        rep(i, 0, n)
        {
            cin >> box[i][0] >> box[i][1] >> box[i][2] >> box[i][3] >> box[i][4];
        }
        int ans = 0;
        while (true)
        {
            // 石を消す処理
            int count = add_point(box);
            ans += count;
            if (count == 0)
                break;

            // 石を下に移動処理
            down_block(box);
            // printf("\n");
            // rep(i, 0, n)
            // {
            //     rep(j, 0, 5)
            //     {
            //         printf("%d ", box[i][j]);
            //     }
            //     printf("\n");
            // }
            // printf("\n");
        }
        cout << ans << endl;
    }

    return 0;
}