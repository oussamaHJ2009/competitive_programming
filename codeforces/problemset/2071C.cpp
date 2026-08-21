// problem link: https://codeforces.com/contest/2071/problem/C
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

vector<vector<int>> T;
vector<bool> path;

int st, en;
vector<int> ans;
bool dfs(int u, int p)
{
    if (u == en)
    {
        ans.push_back(u);
        path[u] = 1;
        return 1;
    }
    for (auto v : T[u])
    {
        if (v != p && dfs(v, u))
        {
            ans.push_back(u);
            path[u] = 1;
            return 1;
        }
    }
    return 0;
}

void solve()
{
    int n;
    cin >> n >> st >> en;
    st--;
    en--;
    T.assign(n, vector<int>());
    path.assign(n, 0);
    ans.clear();
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    dfs(st, -1);
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (path[i])
        {
            vis[i] = 1;
            for (auto s : T[i])
                if (!path[s])
                {
                    vis[s] = 1;
                    queue<int> q;
                    q.push(s);
                    while (!q.empty())
                    {
                        int u = q.front();
                        ans.push_back(u);
                        q.pop();
                        for (auto v : T[u])
                        {
                            if (!vis[v])
                            {
                                q.push(v);
                                vis[v] = 1;
                            }
                        }
                    }
                }
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto a : ans)
    {
        cout << a + 1 << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}