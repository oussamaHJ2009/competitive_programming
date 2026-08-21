// problem link: https://atcoder.jp/contests/abc187/tasks/abc187_f
// authored by a human (i guess?)

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 18;

int n, m;
bool G[N][N]{0};
int dp[1 << N];
const int INF = 239;

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    for (int i = 0; i < n; i++)
        G[i][i] = 1;

    for (int i = 0; i < (1 << n); i++)
    {
        bool f = 1;
        for (int j = 0; j < n; j++)
        {
            if (!((i >> j) & 1))
                continue;
            for (int k = 0; k < n; k++)
            {
                if (!((i >> k) & 1))
                    continue;
                if (!G[j][k])
                    f = 0;
            }
        }
        dp[i] = (f ? 1 : INF);
    }

    for (int s = 1; s < (1 << n); s++)
    {
        for (int t = s; t != 0; t = (t - 1) & s)
        {
            if (dp[s ^ t] != INF && dp[t] != INF)
                dp[s] = min(dp[s], dp[t] + dp[s ^ t]);
        }
    }

    cout << dp[(1 << n) - 1] << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}