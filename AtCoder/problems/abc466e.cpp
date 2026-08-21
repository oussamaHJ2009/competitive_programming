// problem link: https://atcoder.jp/contests/abc466/tasks/abc466_e
// authored by a human (i guess?)

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> c(n, vector<ll>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> c[i][0] >> c[i][1];
    }
    vector<vector<ll>>dp(2*k+1,vector<ll>(n+1,0));
    for (int i = 0; i < 2*k+1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j-1] +c[j-1][i%2];
            if(i)dp[i][j] = max(dp[i][j],dp[i-1][j-1] + c[j-1][1-i%2]);
        }
    }
    cout<<dp[2*k][n];
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