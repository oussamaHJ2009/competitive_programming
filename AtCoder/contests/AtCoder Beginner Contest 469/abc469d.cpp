/*
*created: 2026-08-01 at 13:02:54
*problem: The Big Two, link: https://atcoder.jp/contests/abc469/tasks/abc469_d
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 200005;


unordered_set<int>g[N];
bool vis[N];
ll ans=0;
int T;
void dfs(int u){
    if(vis[u])return;
    vis[u]=1;
    for(auto v:g[u]){
        ans += (g[u].size() + g[v].size() - 1 == T);
        dfs(v);
    }
}

void solve() {
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        g[i].clear();
        vis[i]=0;
    }
    T=m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        
        if(g[a].count(b)){
            T--;
        }else{
            g[a].insert(b);
            g[b].insert(a);
        }
    }
    dfs(0);

    for(int u=0;u<n;u++){
        for(int v:g[u])
        {for(auto w:g[v]){
            if(w==u || g[u].count(w))continue;
            ans += (g[u].size() + g[w].size() == T);
        }}
    }

    cout<<ans/2<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}