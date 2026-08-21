#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

vector<vector<int>>adj;
vector<bool>v;
vector<bool> cnt;

void dfs(int u,int st){
    if(v[u]){
        if(u == st)cnt[u]=true;
        return;
    }
    v[u]=true;
    for (auto v:adj[u])dfs(v,st);
}

void solve() {
    int n,k;
    cin>>n>>k;

    v.assign(n,0);
    adj.assign(n,vector<int>());
    cnt.assign(n,0);

    for(int i=0;i<k;i++){
        int a,b,as,bs;
        cin>>a>>b>>as>>bs;
        if(as>bs)adj[a-1].push_back(b-1);
        else adj[b-1].push_back(a-1);
    }

    for (int i = 0; i < n; i++)
    {
        v.assign(n,0);
        dfs(i,i);
    }
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        ans+=cnt[i];
    }
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