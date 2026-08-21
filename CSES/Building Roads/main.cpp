#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int n,m;
vector<int> g[100001];
vector<bool>vis;
int cnt=0;
void dfs(int at){
    if(vis[at])return;
    vis[at]=true;
    for(auto x:g[at]){
        dfs(x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis.assign(n+1,false);
    vector<int>ans;
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i]){
            dfs(i);
            ans.push_back(i);
            cnt++;
        }
    }
    cout<<cnt-1<<"\n";
    for (int i = 0; i < cnt-1; i++)
    {
        cout<<ans[i]<<" "<<ans[i+1]<<"\n";
    }

    return 0;

}