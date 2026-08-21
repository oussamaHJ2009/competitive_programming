#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int>d(n,-1);
    vector<int>vis(n,false);
    vector<int>p(n,-1);
    vis[0]=1;
    d[0]=1;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(vis[v])continue;
            d[v]=d[u]+1;
            p[v]=u;
            vis[v]=1;
            q.push(v);
        }
    }

    if(d[n-1]==-1){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    vector<int>path{n};
    
    int w=n-1;
    while(w){
        w=p[w];
        path.push_back(w+1);
    }
    reverse(path.begin(),path.end());
    cout<<d[n-1]<<'\n';
    for(auto it:path){
        cout<<it<<' ';
    }
    cout<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}