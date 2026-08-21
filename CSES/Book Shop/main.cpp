#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int>h(n),s(n);
    for (int i = 0; i < n; i++)
    {
        cin>>h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    vector<int>dp(x+1);
    dp[0]=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= h[i]; j--)
        {
            dp[j] = max(dp[j], dp[j-h[i]] + s[i]);
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