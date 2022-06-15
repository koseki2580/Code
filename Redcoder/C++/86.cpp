#include <bits/stdc++.h>
#define rep(i, nn, n) for (int i = nn; i < (n); ++i)
#define rrep(i, nn, n) for (int i = nn; i > (n); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

struct unionfind
{
    vector<int> par;
    unionfind(int x = 0) : par(x, -1) {}

    int find(int x)
    {
        if (par[x] < 0)
            return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (par[y] < par[x])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    int count(int x)
    {
        return -par[find(x)];
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    vector<P> box;
    rep(i, 0, M)
    {
        P a;
        cin >> a.first >> a.second;
        box.push_back(a);
    }
    int ans = 0;

    rep(i, 0, M)
    {
        unionfind uni(N + 5);
        rep(j, 0, M)
        {
            if (i == j)
                continue;
            uni.unite(box[j].first, box[j].second);
        }
        if (uni.count(1) != N)
            ++ans;
    }

    cout << ans << endl;
    return 0;
}