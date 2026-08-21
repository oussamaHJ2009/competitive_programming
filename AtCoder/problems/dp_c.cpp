#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin>>N;
    vector<vector<int>> f(3,vector<int>(N,0));
    for (int i = 0; i < N; i++)
    {
        cin>>f[0][i]>>f[1][i]>>f[2][i];
    }
    vector<vector<int>>dp(3,vector<int>(N+1));
    for (int i = 1; i <= N; i++)
    {
        dp[0][i]=max(dp[1][i-1],dp[2][i-1])+f[0][i-1];
        dp[1][i]=max(dp[0][i-1],dp[2][i-1])+f[1][i-1];
        dp[2][i]=max(dp[1][i-1],dp[0][i-1])+f[2][i-1];
    }
    int ans=0;
    for (int i = 0; i < 3; i++)
    {
        ans=max(dp[i][N],ans);
    }
    cout<<ans<<endl;

    return 0;

}