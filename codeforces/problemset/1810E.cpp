// problem link: https://codeforces.com/contest/1810/problem/E
// authored by a human (i guess?)

#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

using ll = int64_t;

struct dsu
{
    vector<int> e;
    dsu(int n) : e(n,-1) {}
    int find(int u)
    {
        return (e[u] < 0 ? u : e[u] = find(e[u]));
    }
    int sz(int u)
    {
        return -e[find(u)];
    }
    bool unite(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (e[u] > e[v])
            swap(u, v);
        e[u] += e[v];
        e[v] = u;
        return true;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].f;
        a[i].s = i;
    }
    vector<vector<pair<int,int>>> adj(n);
    dsu G(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(a[v]);
        adj[v].push_back(a[u]);
    }

    sort(a.begin(), a.end());

    for (auto [cur,u]:a)
    {
        sort(adj[u].begin(),adj[u].end());
        if(G.sz(u) == 1 && cur!=0)continue;
        for(auto [val,id]:adj[u]){
            if(val <= G.sz(u) || G.sz(id) >= cur)G.unite(id,u);
        }
    }
    

    if(G.sz(0) == n)cout<<"YES\n";
    else cout<<"NO\n";
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