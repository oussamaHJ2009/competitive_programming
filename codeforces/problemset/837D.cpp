// problem link: https://codeforces.com/contest/837/problem/D
// authored by a human (i guess?)

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int N = 201;
const int M = 6001;
const int INF = -1e9;

int dp[N][M]{0};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(2, 0));
    int S = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        while (x % 2 == 0)
            x /= 2, a[i][0]++;
        while (x % 5 == 0)
            x /= 5, a[i][1]++;
        S += a[i][1];
    }
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= S; j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = min(i+1,k); j >= 1; j--)
        {
            for (int l = S; l >= a[i][1]; l--)
            {
                dp[j][l] = max(dp[j - 1][l - a[i][1]] + a[i][0], dp[j][l]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= S; i++)
    {
        ans = max(ans, min(i,dp[k][i]));
    }
    cout<<ans<<'\n';
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