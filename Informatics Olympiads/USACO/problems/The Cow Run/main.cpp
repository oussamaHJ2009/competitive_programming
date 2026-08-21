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
ll INF = 1e9;

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty())
    {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll dp[1001][1001][2];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j][0] = INF, dp[i][j][1] = INF;
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p.begin(), p.end());
    int z = lower_bound(p.begin(), p.end(), 0) - p.begin();
    if (z < n)
        dp[z][z][0] = p[z] * n, dp[z][z][1] = p[z] * n;
    if (z > 0)
        dp[z - 1][z - 1][0] = -p[z - 1] * n, dp[z - 1][z - 1][1] = -p[z - 1] * n;
    for (int sz = 1; sz < n; sz++)
    {
        for (int l = 0; l < n - sz; l++)
        {
            int r = l + sz;

            dp[l][r][0] = min(dp[l + 1][r][0] + abs(p[l + 1] - p[l]) * (n - sz),
                              dp[l + 1][r][1] + abs(p[l] - p[r]) * (n - sz));
            dp[l][r][1] = min(dp[l][r - 1][0] + abs(p[l] - p[r]) * (n - sz),
                              dp[l][r - 1][1] + abs(p[r - 1] - p[r]) * (n - sz));
        }
    }
    cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << '\n';
}

int main()
{
    setIO("cowrun");
    solve();
    return 0;
}