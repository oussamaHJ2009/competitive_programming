#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    vector<int>dp(n+1);
    dp[0]=0;
    for (int i = 1; i <= n; i++)
    {
        dp[i]=dp[i-1]+(s1[i-1]!=s2[i-1]);
        if(i>1)dp[i]=min(dp[i],dp[i-2]+(s1[i-1]!=s1[i-2])+(s2[i-1]!=s2[i-2]));
    }
    cout<<dp[n]<<'\n';
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
}