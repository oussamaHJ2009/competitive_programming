/* stuff you should look for
 *  int overflow, array bounds
 *  special cases (n=1?)
 *  do smth instead of nothing and stay organized
 *  WRITE STUFF DOWN
 *  DON'T GET STUCK ON ONE APPROACH
 */
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int N = 20;
const int mod = 1e9 + 7;

int dp[N][1 << N]{0};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }

    dp[0][1] = 1;
    for (int b = 0; b < (1 << n); b++)
    {
        if (!(b & 1))
            continue;
        for (int u = 0; u < n; u++)
        {
            if (!((b >> u) & 1))
                continue;
            for (int v :adj[u])
            {
                if (!((b >> v) & 1))
                {
                    dp[v][b | (1 << v)] = (dp[v][b | (1 << v)] + dp[u][b]) % mod;
                }
            }
        }
    }

    cout << dp[n - 1][(1 << n) - 1] << '\n';
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