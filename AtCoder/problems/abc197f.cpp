/*
*created: 2026-08-15 at 10:54:46
*problem: Construct a Palindrome, link: https://atcoder.jp/contests/abc197/tasks/abc197_f
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e7;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n);
    vector<vector<bool>>close(n,vector<bool>(n,0));
    while(m--){
        int x,y;char c;
        cin>>x>>y>>c;
        x--;y--;
        adj[x].push_back({y,c-'a'});
        if(y!=x)adj[y].push_back({x,c-'a'});
        close[x][y]=1;
        close[y][x]=1;
    }
    int ans=INF;
    vector<vector<int>>d(n,vector<int>(n,INF));
    queue<pair<int,int>>q;
    d[0][n-1]=0;
    q.push({0,n-1});

    while(!q.empty()){
        auto [ul,ur] = q.front();q.pop();
        if(ul==ur)ans=min(ans,d[ul][ur]);
        else if(close[ul][ur])ans=min(ans,d[ul][ur]+1);
        for(auto [vl,wl]:adj[ul]){
            for(auto [vr,wr]:adj[ur]){
                if(d[vl][vr]==INF && wl==wr){
                    d[vl][vr] = d[ul][ur]+2;
                    q.push({vl,vr});
                }
            }
        }
    }

    if(ans==INF)ans=-1;
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}