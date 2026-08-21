#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, W;
    cin>>N>>W;
    vector<int>v(N+1), w(N+1);
    for (int i = 0; i < N; i++)
    {   
        cin>>w[i]>>v[i];
    }
    vector<vector<ll>>dp(N+1, vector<ll>(W+1));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            dp[i][j]=dp[i-1][j];
            if(w[i-1]<=j){
                dp[i][j] = max(dp[i-1][j-w[i-1]]+v[i-1],dp[i][j]);
            }
        }
    }
    cout<<dp[N][W]<<endl;

    return 0;

}