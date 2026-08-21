/* stuff you should look for
 *  int overflow, array bounds
 *  special cases (n=1?)
 *  do smth instead of nothing and stay organized
 *  WRITE STUFF DOWN
 *  DON'T GET STUCK ON ONE APPROACH
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty())
    {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

const ll INF = 1e18;

struct pt
{
    ll x = 0, y = 0;
};

void solve()
{
    int n, m;
    string s, t;
    cin >> n >> m;
    vector<pt> f(n + 1), b(m + 1);
    cin >> f[0].x >> f[0].y >> b[0].x >> b[0].y >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        f[i].x = f[i - 1].x + (s[i - 1] == 'E' ? 1 : 0) + (s[i - 1] == 'W' ? -1 : 0);
        f[i].y = f[i - 1].y + (s[i - 1] == 'N' ? 1 : 0) + (s[i - 1] == 'S' ? -1 : 0);
    }
    for (int i = 1; i <= m; i++)
    {
        b[i].x = b[i - 1].x + (t[i - 1] == 'E' ? 1 : 0) + (t[i - 1] == 'W' ? -1 : 0);
        b[i].y = b[i - 1].y + (t[i - 1] == 'N' ? 1 : 0) + (t[i - 1] == 'S' ? -1 : 0);
    }

    auto calc = [&](pt A, pt B)
    {
        ll d2 = A.x - B.x, d1 = A.y - B.y;
        return d2 * d2 + d1 * d1;
    };

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + calc(f[i], b[j]));
            if (j)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + calc(f[i], b[j]));
            if (i && j)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + calc(f[i], b[j]));
        }
    }
    cout << dp[n][m] << '\n';
}

int main()
{
    setIO("radio");
    solve();
    return 0;
}