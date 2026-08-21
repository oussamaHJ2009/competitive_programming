#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dp[601][601]{0};

void solve()
{
    int n, W, H;
    cin >> W >> H >> n;
    vector<int> h(n), w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> h[i];

    dp[0][0] = 0;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            dp[i][j] = i * j;
            for (int k = 0; k < n; k++)
            {
                if (h[k] <= i && w[k] <= j)
                {
                    dp[i][j] = min(dp[i][j], dp[h[k]][j - w[k]] + dp[i - h[k]][j]);
                    dp[i][j] = min(dp[i][j], dp[i - h[k]][w[k]] + dp[i][j - w[k]]);
                }
            }
        }
    }

    cout << dp[H][W] << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}