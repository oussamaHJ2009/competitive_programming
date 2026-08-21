#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int a,b;
    cin>>a>>b;
    vector<vector<int>>dp(a+1,vector<int>(b+1,1e9));
    for (int i = 0; i <= min(a,b); i++)
    {
        dp[i][i]=0;
    }
    
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k < max(i,j); k++)
            {
                if(j-k>0)dp[i][j]=min(dp[i][j],dp[i][j-k]+dp[i][k]+1);
                if(i-k>0)dp[i][j]=min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
            }
        }
    }
    cout<<dp[a][b]<<endl;

    return 0;

}