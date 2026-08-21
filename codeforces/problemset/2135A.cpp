#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    vector<queue<int>>cnt(n+1);
    vector<ll>dp(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        dp[i]=dp[i-1];
        cnt[a[i]].push(i);
        if(cnt[a[i]].size()>a[i])cnt[a[i]].pop();
        if(cnt[a[i]].size()==a[i])dp[i]=max(dp[i],dp[cnt[a[i]].front()-1]+a[i]);
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