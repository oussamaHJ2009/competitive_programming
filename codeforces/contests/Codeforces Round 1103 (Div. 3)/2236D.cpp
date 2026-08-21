//problem link: https://codeforces.com/contest/2236/problem/D
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());

    vector<int>dp(n);
    dp[n-1]=1;
    for (int i = n-2; i < 0; i--)
    {
        if(a[i+1]-a[i]<=k)dp[i]=dp[i+1]^1;
        else dp[i]=0;
    }
    
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