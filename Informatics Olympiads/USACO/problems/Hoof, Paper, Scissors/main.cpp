#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    
    int N,K;
    cin>>N>>K;
    vector<int>G(N);
    for (int i = 0; i < N; i++)
    {
        char c;
        cin>>c;
        if(c=='P')G[i]=0;
        if(c=='S')G[i]=1;
        if(c=='H')G[i]=2;
    }
    vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(3,vector<int>(K+1,0)));
    dp[0][0][0]=0;
    dp[0][1][0]=0;
    dp[0][2][0]=0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            int g=G[i-1];
            //choose if swapping is better or not
            if(j)dp[i][(g+1)%3][j]=max(dp[i][(g+1)%3][j],dp[i-1][(g+2)%3][j-1]);
            if(j)dp[i][(g+1)%3][j]=max(dp[i][(g+1)%3][j],dp[i-1][g][j-1]);
            dp[i][(g+1)%3][j]=max(dp[i][(g+1)%3][j],dp[i-1][(g+1)%3][j]);
            //non winning choices -> no need to swap to
            dp[i][g][j]=dp[i-1][g][j];
            dp[i][(g+2)%3][j]=dp[i-1][(g+2)%3][j];
            //count the extra win
            dp[i][(g+1)%3][j]++;
        }
    }
    int ans=0;
    for (int i = 0; i < 3; i++)
    {
        ans=max(ans,dp[N][i][K]);
        
    }
    cout<<ans<<endl;
    return 0;

}