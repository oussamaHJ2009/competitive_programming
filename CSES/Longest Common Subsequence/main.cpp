#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            dp[i][j] = max(dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]), dp[i][j]);
        }
    }
    vector<int> lcs;
    int r = n, c = m;
    while (dp[r][c])
    {
        if (a[r - 1] == b[c - 1])
        {
            lcs.push_back(a[r - 1]);
            r--;
            c--;
        }
        else
        {
            if (dp[r][c - 1] >= dp[r - 1][c])
                c--;
            else
                r--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << dp[n][m] << endl;
    for (auto x : lcs)
    {
        cout << x << " ";
    }

    return 0;
}