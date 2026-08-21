// problem link: https://codeforces.com/contest/839/problem/C
// written by a rando

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int MAXN = 100005;

long double ans = 0;

int d[MAXN];
vector<int> g[MAXN];
bool e[MAXN];

void dfs(int cur, int prev, long double P)
{
    int moves = g[cur].size() - (prev != -1);
    if (!moves)
    {
        ans += d[cur] * P;
    }
    else
    {
        for (auto nxt : g[cur])
        {
            if (nxt != prev)
            {
                d[nxt] = d[cur] + 1;
                dfs(nxt, cur, P / moves);
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    d[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1,1);
    cout << fixed << setprecision(15) << ans << '\n';
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