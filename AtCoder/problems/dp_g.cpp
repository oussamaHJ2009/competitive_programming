#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int N,M;
vector<vector<int>>G;
vector<int>dp;
int dfs(int u){
    if(dp[u])return dp[u];
    for(auto w:G[u]){
        dp[u]=max(dp[u],dfs(w)+1);
    }
    return dp[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>N>>M;
    G.assign(N,vector<int>());
    dp.assign(N,0);
    vector<int>S;
    vector<bool> v(N,false);
    for (int i = 0; i < M; i++)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        G[x].push_back(y);
    }
    for (int i = 0; i < N; i++)
    {
        dfs(i);
    }
    int res=*max_element(dp.begin(),dp.end());
    cout<<res<<endl;

    return 0;

}