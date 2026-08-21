#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int MAXN = 5005;

vector<pair<int,int>> adj[MAXN];

int ans;

void dfs(int v, int u,int K){
    for (auto [nxt,r]:adj[v])
    {
        if(r>=K && nxt != u){
            ans++;
            dfs(nxt,v,K);
        }
    }
}

void solve() {
    int N,Q;
    cin>>N>>Q;
    for(int i=0;i<N-1;i++){
        int u,v,r;
        cin>>u>>v>>r;
        adj[--u].push_back({--v,r});
        adj[v].push_back({u,r});
    }

    while(Q--)
    {
        int st,ki;
        cin>>ki>>st;
        ans=0;
        dfs(--st,-1,ki);
        cout<<ans<<'\n';
    }
}

int main() {
    setIO("mootube");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}