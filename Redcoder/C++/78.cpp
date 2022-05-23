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
    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<int>> J(M + 1, vector<int>(N + 1, 0)), O(M + 1, vector<int>(N + 1, 0)), I(M + 1, vector<int>(N + 1, 0));
    rep(i, 0, M)
    {
        string s;
        cin >> s;
        rep(j, 0, N)
        {
            if (s[j] == 'J')
                J[i + 1][j + 1] = 1;
            else if (s[j] == 'O')
                O[i + 1][j + 1] = 1;
            else
                I[i + 1][j + 1] = 1;
        }
    }
    rep(i, 0, M + 1) rep(j, 0, N)
    {
        J[i][j + 1] += J[i][j];
        O[i][j + 1] += O[i][j];
        I[i][j + 1] += I[i][j];
    }
    rep(i, 0, M) rep(j, 0, N + 1)
    {
        J[i + 1][j] += J[i][j];
        O[i + 1][j] += O[i][j];
        I[i + 1][j] += I[i][j];
    }
    rep(i, 0, K)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int a, b, c;
        a = J[x2][y2] - J[x2][y1 - 1] - J[x1 - 1][y2] + J[x1 - 1][y1 - 1];
        b = O[x2][y2] - O[x2][y1 - 1] - O[x1 - 1][y2] + O[x1 - 1][y1 - 1];
        c = I[x2][y2] - I[x2][y1 - 1] - I[x1 - 1][y2] + I[x1 - 1][y1 - 1];
        printf("%d %d %d\n", a, b, c);
    }
    return 0;
}