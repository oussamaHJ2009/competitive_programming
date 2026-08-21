// problem link: https://codeforces.com/contest/2244/problem/F
// authored by a human (i guess?)

#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

using ll = int64_t;

const int INF = 1e7;

bool sor(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)

        if (a[i] < a[i - 1])
            return false;
    return true;
}
vector<vector<int>> ch;
vector<int> depth;
void dfs(int cur, int d)
{
    depth[cur] = d;
    for (auto nxt : ch[cur])
        dfs(nxt, d + 1);
}

bool cmp(int u, int v)
{
    return depth[u] > depth[v];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n, -1);
    ch.assign(n, vector<int>());
    depth.assign(n, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> p[i];
        ch[--p[i]].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        sort(ch[i].begin(), ch[i].end());
    }
    dfs(0, 0);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, int>> dp(n, {INF, -INF});
    vector<int> leafs(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (a[i])
        {
            dp[i] = {a[i], a[i]};
            leafs[i] = 1;
        }
    }
    vector<int> pro(n);
    iota(pro.begin(), pro.end(), 0);
    sort(pro.begin(), pro.end(), cmp);
    for (auto cur : pro)
    {
        if (ch[cur].empty())
            continue;
        vector<int> vals;
        for (auto u : ch[cur])
        {
            vals.push_back(dp[u].f);
            dp[cur].f = min(dp[u].f, dp[cur].f);
            dp[cur].s = max(dp[u].s, dp[cur].s);
            leafs[cur] += leafs[u];
        }
        auto it = max_element(vals.begin(), vals.end()) + 1;
        rotate(vals.begin(), it, vals.end());
        if (!sor(vals))
        {
            cout << "NO\n";
            return;
        }
        if (leafs[cur] != dp[cur].s - dp[cur].f + 1)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}