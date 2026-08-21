#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int>adj[(int)1e5+3];
int vis[(int)1e5+5];
vector<int>topo;

void dfs(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[v]==1){
            cout<<"IMPOSSIBLE\n";
            exit(0);
        }
        else if(vis[v]==0)dfs(v);
    }
    vis[u]=2;
    topo.push_back(u);
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        adj[i].clear();
        vis[i]=0;
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
    }
    for(int i=0;i<n;i++){
        if(!vis[i])dfs(i);
    }
    reverse(topo.begin(),topo.end());
    for(auto x:topo){
        cout<<x+1<<' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}