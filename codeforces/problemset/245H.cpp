//problem link: https://codeforces.com/contest/245/problem/H
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    vector<vector<bool>>pal(n,vector<bool>(n,false));

    for (int sz = 0; sz < n; sz++)
    {
        for (int l = 0; l+sz < n; l++)
        {
            int r=l+sz;
            if(l<r){
                pal[l][r]=(l+1<r?pal[l+1][r-1]:1)&&(s[l]==s[r]);
                dp[l][r]=dp[l][r-1]+dp[l+1][r]-(l+1<=r-1?dp[l+1][r-1]:0)+pal[l][r];
            }else {
                pal[l][r]=1;
                dp[l][r]=1;
            }
        }
    }
    
    int q;cin>>q;
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<dp[l-1][r-1]<<'\n';
    }
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}