#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty())
    {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}
const int MX = 1005;
vector<vector<ll>> dp;
vector<vector<int>> adj;
vector<ll> m;
void solve()
{
    int N,M,C;
    cin>>N>>M>>C;
    m.assign(N,0);
    dp.assign(MX,vector<ll>(N,-1));
    adj.assign(N,vector<int>());
    for (int i = 0; i < N; i++)
    {
        cin>>m[i];
    }
    for (int i = 0; i < M; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    
    dp[0][0]=0;
    for (int d = 0; d < MX-1; d++)
    {
        for (int u = 0; u < N; u++)
        {
            if(dp[d][u]==-1)continue;
            for(auto v:adj[u]){
                dp[d+1][v] = max(dp[d][u] + m[v],dp[d+1][v]);
            }
        }
    }
    ll ans=0;
    for (int d = 0; d < MX; d++)
    {
        ans=max(ans,dp[d][0] - C*d*d);
    }
    cout<<ans<<'\n';
}

int main()
{
    setIO("time");
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}