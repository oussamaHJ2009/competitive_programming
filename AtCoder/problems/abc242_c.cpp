#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const ll mod = 998244353;
const int MAXN = 1e6+5;

ll dp[MAXN][10];

void solve() {
    int n;
    cin>>n;
    for (int i = 0; i < 10; i++)
    {
        dp[0][i]=1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            dp[i][j]=dp[i-1][j]%mod;
            if(j<9)dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
            if(j>1)dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;

        }
    }
    ll ans=0;
    for (int i = 1; i < 10; i++)
    {
        ans+=dp[n-1][i];
        ans%=mod;
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}