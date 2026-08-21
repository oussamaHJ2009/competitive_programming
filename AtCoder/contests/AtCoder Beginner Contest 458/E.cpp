#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int X1,X2,X3;
    cin>>X1>>X2>>X3;
    vector<vector<ll>>dp(X1+X2+X3+1,vector<ll>(4,0));
    ll cnt1=0,cnt2=0,cnt3=0;
    dp[0][1]=1;dp[0][2]=1;dp[0][3]=1;
    for (int i = 1; i <= X1+X2+X3; i++)
    {
        dp[i][1]=(dp[i-1][1]+mod+dp[i-1][2])%mod;
        dp[i][2]=((dp[i-1][1]+mod+dp[i-1][3])%mod+dp[i-1][2])%mod;
        dp[i][3]=(dp[i-1][3]+mod+dp[i-1][2])%mod;
    }
    

    return 0;

}