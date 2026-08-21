/* stuff you should look for
 *  int overflow, array bounds
 *  special cases (n=1?)
 *  do smth instead of nothing and stay organized
 *  WRITE STUFF DOWN
 *  DON'T GET STUCK ON ONE APPROACH
 */
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto &t : s)
        cin >> t;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + 1 < n && j + 1 < n)
            {
                if (s[i][j + 1] <= s[i + 1][j])
                    dp[i][j + 1] |= dp[i][j];
                if (s[i][j + 1] >= s[i + 1][j])
                    dp[i + 1][j] |= dp[i][j];
            }
            else if (i + 1 < n)
                dp[i + 1][j] |= dp[i][j];
            else if (j + 1 < n)
                dp[i][j + 1] |= dp[i][j];
        }
    }
    string ans = "";
    ans += s[0][0];
    for (int d = 1; d < 2 * n - 1; d++)
    {
        int im = -1, jm = -1;
        for (int i = min(n - 1, d); i >= 0; i--)
        {
            if (d - i >= n)
                break;
            if (!((i && dp[i - 1][d - i]) || (d - i && dp[i][d - i - 1])))
                dp[i][d - i] = 0;
            if (dp[i][d - i] == 0)
                continue;
            if (im == -1)
                im = i, jm = d - i;
            else if (s[i][d - i] < s[im][jm])
                im = i, jm = d - i;
        }
        for (int i = min(n - 1, d); i >= 0; i--)
        {
            if (d - i >= n)
                break;
            if (s[im][jm] < s[i][d - i])
                dp[i][d - i] = 0;
        }
        ans += s[im][jm];
    }

    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}

//genuinly this is some serious bash fr