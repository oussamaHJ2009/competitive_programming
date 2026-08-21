#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const int inf=INT32_MAX;
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>a(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        a[v]|=(1<<u);
        a[u]|=(1<<v);
    }
    vector<int>dp(1<<n,inf);
    for (int S = 0; S < (1<<n); S++)
    {
        bool c=true;
        for (int u = 0; u < n; u++)
        {
            if(((S>>u) & 1) != 0){
                if(((a[u]|(1<<u)) & S) != S){
                    c=0;
                    break;
                }
            }
        }
        if(c==1)dp[S]=1;
    }
    
    for(int mask=0;mask < (1<<n);mask++){
        for (int submask = mask; submask != 0; submask=(submask-1) & mask)
        {
            int subset=mask^submask;
            if(dp[subset]!=inf && dp[submask]!=inf){
                dp[mask] = min(dp[mask], dp[subset] + dp[submask]);
            }
        }
    }

    cout<<dp[(1<<n)-1];
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