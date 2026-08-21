#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,K;
    cin>>N>>K;
    vector<int>h(N);
    for (int i = 0; i < N; i++)
    {
        cin>>h[i];
    }
    vector<ll>dp(N+1,1e9+1);
    dp[0]=0;dp[1]=0;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if(i-j>0)dp[i]=min(dp[i-j]+abs(h[i-1]-h[i-j-1]),dp[i]);
        }
    }
    cout<<dp[N]<<endl;

    return 0;

}