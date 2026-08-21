#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9+7;
const int N = 1e5+5;

vector<int> adj[N];
int dp[N]{};
bool vis[N]{};


int dfs(int u){
    if(vis[u])return dp[u];
    vis[u]=1;
    for(auto v:adj[u]){
        dp[u] = (dp[u] + dfs(v))%mod;
    }
    return dp[u];
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
    }

    dp[n-1]=1;
    vis[n-1]=1;
    cout<<dfs(0)<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}