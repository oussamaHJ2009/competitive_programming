// problem link: https://atcoder.jp/contests/arc224/tasks/arc224_c
// authored by a human (i guess?)

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

vector<vector<int>> adj;
vector<int> a;

void dfs(int u)
{
    for (auto v : adj[u])
        if (a[v] == -1)
        {
            a[v] = a[u]+1;
            dfs(v);
        }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    col = 0;
    adj.assign(n, vector<int>());
    a.assign(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    a[0]=0;
    dfs(0);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
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