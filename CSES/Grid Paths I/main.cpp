/* stuff you should look for
*  int overflow, array bounds
*  special cases (n=1?)
*  do smth instead of nothing and stay organized
*  WRITE STUFF DOWN
*  DON'T GET STUCK ON ONE APPROACH
*/
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin>>n;
    vector<vector<bool>>G(n,vector<bool>(n,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;cin>>c;
            if(c=='*')G[i][j]=1;
        }
        
    }

    vector<vector<int>>dp(n,vector<int>(n,0));
    if(!G[0][0])dp[0][0]=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(G[i][j])continue;
            if(i)dp[i][j]+=dp[i-1][j];
            if(j)dp[i][j]+=dp[i][j-1];
            dp[i][j]%=mod;
        }
        
    }
    cout<<dp[n-1][n-1]<<'\n';
    
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