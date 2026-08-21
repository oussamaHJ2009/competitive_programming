#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<vector<ll>>dp(1e6,vector<ll>(2,0));
        dp[0][0]=1;
        dp[0][1]=1;
        for (int i = 1; i < 1e6; i++)
        {
            dp[i][0]=(dp[i-1][1]+(4*dp[i-1][0]))%mod;
            dp[i][1]=(dp[i-1][0]+(2*dp[i-1][1]))%mod;
        }
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<(dp[n-1][1]+dp[n-1][0])%mod<<endl;
    }

    return 0;

}