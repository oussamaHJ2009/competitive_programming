#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>>dp(2,vector<int>(n+1,1e9));
    dp[1][0]=0;
    for(int i=1;i<=n;i++){
        dp[0][i]=min(dp[0][i],dp[1][i-1]+a[i-1]);
        dp[1][i]=min(dp[1][i],dp[0][i-1]);
        if(i>1){
            dp[0][i]=min(dp[0][i],dp[1][i-2]+a[i-2]+a[i-1]);
            dp[1][i]=min(dp[1][i],dp[0][i-2]);
        }
    }
    cout<<min(dp[0][n],dp[1][n])<<'\n';
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