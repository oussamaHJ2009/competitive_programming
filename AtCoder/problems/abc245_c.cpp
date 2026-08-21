#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = (dp[i - 1][0] & (abs(a[i] - a[i - 1]) <= k)) || (dp[i - 1][1] & (abs(a[i] - b[i - 1]) <= k));
        dp[i][1] = (dp[i - 1][0] & (abs(b[i] - a[i - 1]) <= k)) || (dp[i - 1][1] & (abs(b[i] - b[i - 1]) <= k));
    }
    cout<<(dp[n-1][0]||dp[n-1][1]?"Yes":"No")<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}