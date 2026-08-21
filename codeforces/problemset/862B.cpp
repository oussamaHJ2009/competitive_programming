//problem link: https://codeforces.com/contest/862/problem/B
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    vector<int>d(n,-1);
    d[0]=0;
    queue<int>q;
    q.push(0);
    vector<ll>cnt(2,0);
    cnt[0]++;
    while (!q.empty())
    {
        int cur = q.front();q.pop();
        for(auto u:adj[cur]){
            if(d[u]==-1){
                d[u]=d[cur]+1;
                cnt[d[u]%2]++;
                q.push(u);
            }
        }
    }
    ll ans=cnt[0]*cnt[1] - n + 1;
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}