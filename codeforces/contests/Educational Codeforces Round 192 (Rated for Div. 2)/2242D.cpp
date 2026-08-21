//problem link: https://codeforces.com/contest/2242/problem/D
//authored by a human (i guess?)


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
vector<vector<int>>dp;
void solve() {
    string a,b;
    cin>>a>>b;
    int n=(int)a.size(),m=(int)b.size();
    dp.assign(n+1,vector<int>(m+1,0));
    vector<int>mda(n+1,0),mdb(m+1,0);
    for (int i = 0; i < n; i++)
    {
        mda[i+1]=(mda[i]+(a[i]-'0'))%10;
    }
    for (int i = 0; i < m; i++)
    {
        mdb[i+1]=(mdb[i]+(b[i]-'0'))%10;
    }
    
    if(mda[n]!=mdb[m]){cout<<"-1\n";return;}
    dp[0][0]=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j]=max({dp[i-1][j],dp[i][j-1],(mda[i]==mdb[j])+dp[i-1][j-1]});
        }
        
    }
    cout<<dp[n][m]<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}