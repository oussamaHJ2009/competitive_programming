// problem link: https://codeforces.com/contest/2107/problem/D
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
vector<bool> tofa7a;
vector<int> d;
bool klit = 0;
int s = 0, e = 0, l = 0;

void dfs1(int u, int p, int &nd)
{
    if (p == -1)
        d[u] = 0;
    else
        d[u] = d[p] + 1;

    if (d[nd] <= d[u])
    {
        if (d[u] == d[nd])
            nd = max(nd, u);
        else
            nd = u;
    }

    l = max(l, d[u]);

    for (auto v : T[u])
        if (tofa7a[v] && v != p)
            dfs1(v, u, nd);
}
void dfs2(int u, int p)
{
    tofa7a[u] = 0;
    if (u == e)
    {
        klit = 1;
        return;
    }
    for (auto v : T[u])
    {
        if (tofa7a[v] && v != p)
        {
            if (klit)return;
            dfs2(v, u);
        }
    }
    if (klit)
        return;
    tofa7a[u] = 1;
}

void solve()
{
    int n;
    cin >> n;
    T.assign(n, vector<int>());
    tofa7a.assign(n, true);
    d.assign(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        T[a].push_back(b);
        T[b].push_back(a);
    }

    vector<tuple<int, int, int>> ans;
    int st = 0;
    while (st < n)
    {
        while (st < n && !tofa7a[st])
            st++;
        if (st == n)
            break;
        l = 0, s = st, klit = 0;
        dfs1(st, -1, s);
        e=s;
        dfs1(s, -1, e);
        ans.push_back({l + 1, max(s + 1, e + 1), min(s + 1, e + 1)});
        dfs2(s, -1);
    }
    sort(ans.begin(), ans.end(), greater<tuple<int, int, int>>());
    for (auto [x1, x2, x3] : ans)
    {
        cout << x1 << ' ' << x2 << ' ' << x3 << ' ';
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