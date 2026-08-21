/*
mistake_1:didn't notice the reverse knapsack(vals as weights and weights as vals)
mistake_2:forgot dp[0]=0 somehow
*/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,W;
    cin>>N>>W;
    vector<int>w(N),v(N);
    int S=0;
    for(int i=0;i<N;i++){
        cin>>w[i]>>v[i];
        S+=v[i];
    }
    
    vector<int>dp(S+1,1e9);
    dp[0]=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = S; j >= v[i]; j--)
        {
            dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
        }
        
    }
    int ans=0;
    for (int i = S; i >= 0; i--)
    {
        if(dp[i]<=W){ans=i;break;}
    }

    cout<<ans<<endl;
    return 0;

}