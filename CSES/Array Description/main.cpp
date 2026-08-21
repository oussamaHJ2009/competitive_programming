/* stuff you should look for
 *  int overflow, array bounds
 *  special cases (n=1?)
 *  do smth instead of nothing and stay organized
 *  WRITE STUFF DOWN
 *  DON'T GET STUCK ON ONE APPROACH
 */
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        if (a[0] == 0 || a[0] == i)
            dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == j || a[i] == 0)
            {
                for (int k = -1; k <= 1; k++)
                {
                    if (j + k > 0 && j + k <= m)
                        (dp[i][j] += dp[i - 1][j + k]) %= mod;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        (ans += dp[n - 1][i]) %= mod;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}