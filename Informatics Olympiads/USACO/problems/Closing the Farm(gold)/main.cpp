#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty())
    {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

vector<int> to, sz;
int find(int u)
{
    return (to[u] != u ? to[u]=find(to[u]) : u);
}
void unite(int u, int v)
{
    u = find(u);
    v = find(v);
    if (v == u)
        return;
    if (sz[v] > sz[u])
        swap(u, v);
    sz[u] += sz[v];
    to[v] = u;
}

void solve()
{
    int n, m;
    cin>>n>>m;
    to.resize(n);
    iota(to.begin(),to.end(),0);
    sz.assign(n, 1);
    vector<vector<int>>g(n);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int>q(n);
    for (int i = n-1; i >=0; i--)cin>>q[i];
    vector<bool>in(n,false),ans(n);
    for (int i = 0; i < n; i++)
    {
        int cur=q[i]-1;
        in[cur]=true;
        for (auto u:g[cur])
        {
            if(in[u])unite(u,cur);
        }
        ans[n-1-i]=(sz[find(cur)]==i+1);
    }
    for (auto &&i : ans)
    {
        if(i)cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    

}

int main()
{
    setIO("closing");
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}