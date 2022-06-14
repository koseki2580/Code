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
        {
            swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    unionfind box(n + 5);
    rep(i, 0, q)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
            box.unite(b, c);
        else
        {
            bool aa = box.same(b, c);
            if (aa == true)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}
