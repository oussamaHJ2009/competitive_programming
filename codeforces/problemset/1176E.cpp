//problem link: https://codeforces.com/problemset/problem/1176/E
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    vector<int> d(n,-1);
    vector<int>cnt(2,0);
    queue<int>q;
    q.push(0);
    cnt[0]++;
    d[0]=0;
    while (!q.empty())
    {
        int cur=q.front();q.pop();
        for (auto u:adj[cur])
        {
            if(d[u]==-1){
                q.push(u);
                d[u]=d[cur]+1;
                cnt[d[u]%2]++;
            }
        }
    }
    if(cnt[0]<cnt[1]){
        cout<<cnt[0]<<'\n';
        for (int i = 0; i < n; i++)
        {
            if(d[i]%2 == 0)cout<<i+1<<' ';
        }
    }else{
        cout<<cnt[1]<<'\n';
        for (int i = 0; i < n; i++)
        {
            if(d[i]%2)cout<<i+1<<' ';
        }
    }
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}