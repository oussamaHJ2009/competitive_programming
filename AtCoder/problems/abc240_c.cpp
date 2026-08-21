#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int>a(n),b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    dp[0][0]=1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            //dp[i][j]=dp[i-1][j];
            if(a[i-1]<=j)dp[i][j] |= dp[i-1][j-a[i-1]];
            if(b[i-1]<=j)dp[i][j] |= dp[i-1][j-b[i-1]];
        }
    }
    if(dp[n][x])cout<<"Yes\n";
    else cout<<"No\n";
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