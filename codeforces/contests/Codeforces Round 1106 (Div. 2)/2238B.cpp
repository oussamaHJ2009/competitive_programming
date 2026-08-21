//problem link: https://codeforces.com/contest/2238/problem/B
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    ll n;
    cin>>n;
    ll ans=0;
    for (ll b = 1; b <= n; b++)
    {
        ans+=(n/b)*(n/b);
    }
    
    cout<<ans<<'\n';
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