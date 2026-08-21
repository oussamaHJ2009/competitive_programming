/* stuff you should look for
 *  int overflow, array bounds
 *  special cases (n=1?)
 *  do smth instead of nothing and stay organized
 *  WRITE STUFF DOWN
 *  DON'T GET STUCK ON ONE APPROACH
 */
#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty())
    {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p1(n), p2(n);
    for (int i = 0; i < n; i++)
        cin >> p1[i];
    for (int i = 0; i < n; i++)
        cin >> p2[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    auto v = [](int a, int b)
    { return abs(a - b) <= 4; };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = max({dp[i - 1][j],
                            dp[i][j - 1],
                            dp[i - 1][j - 1] + v(p1[i - 1], p2[j - 1])});
        }
    }
    cout << dp[n][n] << '\n';
}

int main()
{
    setIO("nocross");
    solve();
    return 0;
}