#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353

vector<vector<int>> g;
vector<int> visited;
pair<int, int> lost;

void dfs(int u)
{
    if (visited[u])
        return;
    visited[u] = true;
    for (auto v : g[u])
    {
        if (make_pair(min(u,v), max(u,v)) != lost)
            dfs(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true)
    {
        int p, c;
        cin >> p >> c;
        if(!p && !c)break;
        vector<pair<int, int>> E(c);
        g.assign(p,vector<int>(0));
        visited.assign(p,false);
        for (int i = 0; i < c; i++)
        {
            int a, b;
            cin >> a >> b;
            E[i] = make_pair(min(a,b), max(a,b));
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bool y=true;
        for (auto e:E)
        {
            lost=e;
            dfs(0);
            for (int i = 0; i < p; i++)
            {
                if(!visited[i])y=false;
            }
            visited.assign(p,false);
        }
        if(!y)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}