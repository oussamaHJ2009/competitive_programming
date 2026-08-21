/*
*created: 2026-08-11 at 14:34:54
*problem: Pre-Palindrome, link: https://atcoder.jp/contests/abc468/tasks/abc468_d
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    ll ans=0;
    for(int sz=0;sz<n;sz++){
        for(int l=0;l<n-sz;l++){
            int r=l+sz;
            if(sz==0)
                dp[l][r]=2;
            else if(sz==1){
                dp[l][r]=(s[l]==s[r])+1;
            }else
                if(dp[l+1][r-1])dp[l][r]=dp[l+1][r-1]-(s[l]!=s[r]);
            
            if(dp[l][r]>0)ans++;
        }
    }
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}