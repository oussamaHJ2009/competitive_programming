#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>>g(n);
    vector<int>deg(n,0);
    for (int i = 0; i < n-1; i++)
    {
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        v--;u--;
        if(x>y){
            g[v].push_back(u);
            deg[u]++;
        }else{
            g[u].push_back(v);
            deg[v]++;
        }
    }
    queue<int>q;
    for (int i = 0; i < n; i++)
    {
        if(!deg[i])q.push(i);
    }
    vector<int>p(n);
    int cnt=0;
    while (!q.empty())
    {
        int cur=q.front();
        q.pop();
        p[cur]=++cnt;
        for(auto nxt:g[cur]){
            deg[nxt]--;
            if(!deg[nxt]){
                q.push(nxt);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<p[i]<<' ';
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