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

vector<vector<int>> g;
vector<int> col;
vector<int> a;
int s[2]{0, 0}, c[2]{0, 0};
void dfs(int u, int p)
{
    if(p!=-1)col[u] = col[p]^1;
    s[col[u]] += a[u];
    c[col[u]]++;
    for (auto v : g[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    col.assign(n, -1);
    g.assign(n, vector<int>());
    a.assign(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    col[0]=0;
    dfs(0, -1);
    
    if(s[0]%12 == s[1]%12){
        cout<<n;
    }else if(s[0]%12 == (s[1]+1)%12){
        cout<<c[0];
    }else if((s[0]+1)%12 == s[1]%12){
        cout<<c[1];
    }else{
        cout<<0;
    }
}

int main()
{
    setIO("clocktree");
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}