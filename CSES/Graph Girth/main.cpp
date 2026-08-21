#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    while(m--){
        int x,y;cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool>vis(n,0);
    queue<pair<int,int>>q;
    int ans=INF;
    vector<int>d(n,INF);
    for(int st=0;st<n;st++){
        q.push({st,-1});
        vis.assign(n,0);
        d.assign(n,INF);
        vis[st]=1;
        d[st]=0;
        while(!q.empty()){
            auto [u,p]=q.front();
            q.pop();
            for(auto v:adj[u])
            if(!vis[v]){
                d[v]=d[u]+1;
                vis[v]=1;
                q.push({v,u});
            }else if(v!=p){
                ans=min(ans,d[u]+d[v]+1);
            }
        }
    }

    if(ans<INF)cout<<ans<<'\n';
    else cout<<"-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}