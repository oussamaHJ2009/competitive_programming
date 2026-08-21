#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const int mod = 1e9+7;
void solve() {
    int n;
    cin>>n;
    int x = n*(n+1);
    if(x%4){cout<<0<<'\n';return;}
    x/=4;
    vector<ll>dp(x+1,0);
    dp[0]=1;
    for (int i = 1; i < n; i++)
    {
        for (int j = x; j >= i; j--)
        {
            dp[j] += dp[j-i];
            dp[j]%=mod;
        }
    }
    cout<<dp[x]<<'\n';
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