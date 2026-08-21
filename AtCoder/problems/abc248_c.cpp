#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 998244353;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,K,M;
    cin>>N>>M>>K;
    vector<vector<int>>dp(N+1,vector<int>(K+1));
    dp[0][0]=1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            for (int k = 1; k <= M; k++)
            {
                if(j-k>=0){
                    dp[i][j]+=dp[i-1][j-k];
                    dp[i][j]%=mod;
                }
            }
            
        }
    }
    int ans=0;
    for (int i = 1; i <= K; i++)
    {
        ans+=dp[N][i];
        ans%=mod;
    }
    cout<<ans<<endl;

    return 0;

}