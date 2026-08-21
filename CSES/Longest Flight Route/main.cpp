#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = -1e9;

vector<vector<int>>adj;
vector<bool>vis;
vector<int>mem;
vector<int>par;

int dfs(int u){
    if(vis[u])return mem[u];
    vis[u]=1;
    for(int v:adj[u]){
        dfs(v);
        if(mem[v]!=INF && mem[v]+1>mem[u]){
            mem[u]=mem[v]+1;
            par[u]=v;
        }
    }
    return mem[u];
}

void solve() {
    int n,m;
    cin>>n>>m;

    adj.assign(n,vector<int>());
    vis.assign(n,0);
    mem.assign(n,INF);
    par.assign(n,-1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[b].push_back(a);
    }

    mem[0]=1;

    dfs(n-1);

    if(mem[n-1]==INF){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    vector<int>path;
    for(int v=n-1;v!=-1;v=par[v]){
        path.push_back(v);
    }
    reverse(path.begin(),path.end());
    cout<<mem[n-1]<<'\n';
    for(auto x:path)cout<<x+1<<' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}