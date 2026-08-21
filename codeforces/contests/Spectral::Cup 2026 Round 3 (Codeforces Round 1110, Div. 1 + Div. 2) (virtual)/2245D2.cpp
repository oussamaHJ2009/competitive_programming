//problem link: https://codeforces.com/contest/2245/problem/D2
//authored by a human (i guess?)

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<pair<int,int>>>g;
vector<int>a;
vector<bool>vis;
int cur=1;

// talkiz ostouri!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void dfs(int u){
    vis[u]=true;
    for(auto [o,v]:g[u]){
        if(o==1)a[v];
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    a.assign(n,0);
    g.assign(n,vector<pair<int,int>>());
    vis.assign(m,0);
    for(int i=0;i<m;i++){
        int o,u,v;
        cin>>o>>u>>v;
        v--;u--;
        if(u==v){
            if(o==1)a[u]=cur;
            else a[u]=cur;
        }else{
            g[u].push_back({v,o});
            g[v].push_back({u,o});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}