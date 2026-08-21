/*
*created: 2026-08-01 at 16:15:43
*problem: C. Maximize the Score, link: https://codeforces.com/contest/2248/problem/C
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin>>n;
    vector<ll>L(n+1,-1);
    vector<ll>R(n+1,-1);
    vector<ll>dp(2*n+1);
    ll a;
    dp[0]=0;
    for(ll i=1;i<=2*n;i++){
        cin>>a;
        dp[i]=dp[i-1];
        if(L[a]==-1){
            L[a]=i;
        }
        else {
            R[a]=i;
        }
        if(R[a]!=-1)dp[i]=max(dp[i],dp[L[a]-1] + (R[a]-L[a]+1)*(R[a]-L[a]));
    }
    cout<<dp[2*n] + 2*n<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}