#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const int mod = 1e9 + 7;
void solve()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
    vector<vector<int>> dp(h, vector<int>(w, 0));
    dp[0][0] = 1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (i > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            dp[i][j] *= a[i][j];
        }
    }
    cout << dp[h - 1][w - 1];
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