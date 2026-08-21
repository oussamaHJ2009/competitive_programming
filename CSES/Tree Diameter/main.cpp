#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int MAXN = 200005;

vector<int>tree[MAXN];
int d[MAXN];

void dfs(int cur,int prev){
    for (auto nxt:tree[cur])
    {
        if(prev!=nxt){
            d[nxt]=d[cur]+1;
            dfs(nxt,cur);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    d[0]=0;
    dfs(0,-1);
    int s=0;
    for (int i = 0; i < n; i++)
    {
        if(d[i]>d[s])s=i;
    }
    d[s]=0;
    dfs(s,-1);
    int ans=0;
    for (int i = 0; i < n; i++)ans=max(ans,d[i]);
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