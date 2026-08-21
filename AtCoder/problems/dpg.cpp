/*
 *created: 2026-08-20 at 14:14:13
 *problem: Longest Path, link: https://atcoder.jp/contests/dp/tasks/dp_g
 *author: a human
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = -1e6;

vector<vector<int>> adj;
vector<int> dp;

int dfs(int u)
{
    if (dp[u])
        return dp[u];
    for (auto v : adj[u])
    {
        dp[u] = max(dfs(v) + 1, dp[u]);
    }
    return dp[u];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    adj.assign(n, vector<int>());
    dp.assign(n, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < n; i++)

        dfs(i);

    int ans = *max_element(dp.begin(), dp.end());

    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}