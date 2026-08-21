#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,x;
    cin>>n>>x;
    vector<int>c(n);
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
    }
    vector<int>dp(x+1);
    dp[0]=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = c[i]; j <= x; j++)
        {
            dp[j]+=dp[j-c[i]];
            dp[j]%=mod;
        }
    }
    
    cout<<dp[x]<<endl;

    return 0;

}