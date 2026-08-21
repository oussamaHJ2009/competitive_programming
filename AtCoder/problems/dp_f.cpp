#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int v=n,h=m;
    string ans="";
    while (v>0 && h>0)
    {
        if(s[v-1]==t[h-1]){
            ans+=s[v-1];
            h--;v--;
        }else{
            if(dp[v-1][h]<dp[v][h-1])h--;
            else v--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
    return 0;

}