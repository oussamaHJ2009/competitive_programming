#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n,m;
vector<int>a,b;

int popc(int x){
    return __builtin_popcount(x);
}

vector<vector<int>>dp(21,vector<int>(1<<20,-1));
vector<int>sum(1<<20,0);

bool find(int cur, int S){
    if(dp[cur][S]==1)return true;
    if(cur==n){dp[cur][S]=1;return true;}
    if(S==0)return false;
    int s=0;
    for(int T=S;T!=0;T=(T-1)&S){
        if(sum[T]==a[cur]){
            if(popc(S^T) < n-cur-1 || dp[cur+1][S^T]==0)continue;
            if(dp[cur+1][S^T]==1){
                dp[cur][S] = 1;
                return true;
            }
            if(find(cur+1, S^T)){
                dp[cur][S] = 1;
                return true;
            }
        }
    }
    dp[cur][S]=0;
    return false;
}

void solve(){
    cin>>n>>m;
    a.assign(n,0),b.assign(m,0);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    for(int msk=0;msk<(1<<m);msk++)
        for(int i=0;i<m;i++)
            if((msk>>i)&1)
                sum[msk]+=b[i];
    
    if(find(0,(1<<m) - 1))cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}