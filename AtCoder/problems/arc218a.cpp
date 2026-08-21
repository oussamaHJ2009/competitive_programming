//problem link: https://atcoder.jp/contests/arc218/tasks/arc218_a
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const int mod = 998244353;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>cnt(n,vector<int>(m*n+1,0));
    ll nm=1;
    for (int i = 0; i < n; i++)
    {
        nm=(nm*m)%mod;
        for (int j = 0; j < m; j++)
        {
            int x;cin>>x;
            cnt[i][x]++;
        }
    }
    
    ll ans=0;
    for (int k = 1; k <= n*m; k++)
    {
        ll p=1;
        for (int i = 0; i < n; i++)
        {
            p=(p*(m-cnt[i][k]))%mod;
        }
        ans=(ans+nm+mod-p)%mod;
    }
    
    
    cout<<ans<<'\n';
    
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