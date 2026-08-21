// problem link: https://atcoder.jp/contests/abc465/tasks/abc465_e
// authored by a human (i guess?)

#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

using ll = int64_t;
ll dp[501][1 << 10][3][2];

void solve()
{
    string N;
    cin >> N;
    int n = N.size();
    ll res = 0;
    for (int b = 0; b < (1 << 10); b++)
        for (int m = 0; m < 3; m++)
            for (int l = 0; l < 2; l++)
                dp[0][b][m][l] = 0;
    dp[0][0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int b = 0; b < (1 << 10); b++)
            for (int m = 0; m < 3; m++)
                for (int l = 0; l < 2; l++)
                    dp[i + 1][b][m][l] = 0;

        for (int b = 0; b < (1 << 10); b++)
        {
            for (int m = 0; m < 3; m++)
            {
                for (int d = 0; d < 10; d++)
                {
                    int c = N[i] - '0';
                    int nb = (b == 0 && d == 0 ? 0 : b | (1 << d));
                    int nm = (10*m + d) % 3;
                    if (d <= c)
                    {
                        dp[i + 1][nb][nm][d == c ? 0 : 1] += dp[i][b][m][0];
                        dp[i + 1][nb][nm][d == c ? 0 : 1] %= mod;
                    }
                    dp[i + 1][nb][nm][1] += dp[i][b][m][1];
                    dp[i + 1][nb][nm][1] %= mod;
                }
            }
        }
    }
    for (int b = 1; b < (1 << 10); b++)
    {
        for (int m = 0; m < 3; m++)
        {
            for (int l = 0; l < 2; l++)
            {
                int cond = 0;
                if (m==0)
                    cond++;
                if (__builtin_popcount(b) == 3)
                    cond++;
                if ((b >> 3) & 1)
                    cond++;
                if (cond == 1)
                {
                    res += dp[n][b][m][l];
                    res %= mod;
                }
            }
        }
    }

    cout << res << '\n';
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