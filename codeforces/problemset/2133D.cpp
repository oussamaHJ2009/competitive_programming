#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>h(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>h[i];
    }
    vector<ll>dp(n+1,0);
    dp[1]=h[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i]=dp[i-1]+h[i]-1;
        dp[i]=min(dp[i],dp[i-2]+h[i-1]+max(h[i]-i+1,0));
    }
    cout<<dp[n]<<'\n';
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