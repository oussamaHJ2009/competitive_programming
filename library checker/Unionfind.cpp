// problem link: https://judge.yosupo.jp/problem/joinfind
// written by u rando

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

struct DSU
{
    vector<int> e;
    DSU(int n)
    {
        e.assign(n, -1);
    }
    int find(int u)
    {
        return (e[u] < 0 ? u : e[u]=find(e[u]));
    }
    void unite(int u, int v)
    {
        u = find(u), v = find(v);
        if (v == u)
            return;
        if (e[v] < e[u])
            swap(u, v);
        e[u] += e[v];
        e[v] = u;
    }
    bool same(int u, int v)
    {
        return find(u) == find(v);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    for (int i = 0; i < q; i++)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if (t)
            cout << dsu.same(u, v) << '\n';
        else
            dsu.unite(u, v);
    }
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