#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n,x;
    cin>>n>>x;
    vector<int>c(n);
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
    }
    vector<int>dp(x+1);
    dp[0]=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= 0; j--)
        {
            int cost=c[i]*(n-i);
            if(cost<=j)dp[j]=max(dp[j],dp[j-cost]+1);
        }
    }
    cout<<dp[x]<<endl;

    return 0;

}