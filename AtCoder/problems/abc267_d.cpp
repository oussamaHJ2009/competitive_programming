#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,M;
    cin>>N>>M;
    vector<ll>A(N);
    for (int i = 0; i < N; i++)
    {
        cin>>A[i];
    }
    vector<vector<ll>>dp(N+1,vector<ll>(M+1,0));
    dp[0][0]=0;
    dp[0][1]=-1e18;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if(j>i)dp[i][j]=-1e18;
            else dp[i][j]=max(dp[i-1][j-1]+j*A[i-1],dp[i-1][j]);
        }
    }
    cout<<dp[N][M]<<endl;

    return 0;

}