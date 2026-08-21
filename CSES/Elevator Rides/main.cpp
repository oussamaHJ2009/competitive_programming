#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9;

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int>w(n);
    for(int i=0;i<n;i++)cin>>w[i];
    vector<pair<int,int>>dp(1<<n,{INF,INF});
    dp[0]={1,0};
    for(int s=0;s<(1<<n);s++){
        for(int i=0;i<n;i++){
            if(s>>i & 1){
                int c = dp[s ^ (1<<i)].first;
                int v = dp[s ^ (1<<i)].second + w[i];
                if(v<=x){
                    dp[s] = min(dp[s], {c,v});
                }else{
                    dp[s] = min(dp[s], {c+1,w[i]});
                }
            }
        }
    }
    cout<<dp[(1<<n) - 1].first<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}