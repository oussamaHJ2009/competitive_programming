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
const ll INF = 1e18;

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty())
    {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct pt
{
    ll x, y;
};

ll D(pt a, pt b)
{
    ll p = a.x - b.x, q = a.y - b.y;
    return p * p + q * q;
}

void solve()
{
    int H, G;
    cin >> H >> G;
    vector<pt> h(H), g(G);
    for (int i = 0; i < H; i++)
        cin >> h[i].x >> h[i].y;
    for (int i = 0; i < G; i++)
        cin >> g[i].x >> g[i].y;

    vector<vector<vector<ll>>> dp(H + 1, vector<vector<ll>>(G + 1, vector<ll>(2, INF)));
    dp[1][0][0] = 0;

    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j <= G; j++)
        {
            if (i > 1)
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + D(h[i - 1], h[i - 2]));
            if (j > 1)
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + D(g[j - 1], g[j - 2]));
            if (i > 0 && j > 0)
            {
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + D(h[i - 1], g[j - 1]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + D(h[i - 1], g[j - 1]));
            }
        }
    }

    cout << dp[H][G][0] << '\n';
}

int main()
{
    setIO("checklist");
    solve();
    return 0;
}