//problem link: https://atcoder.jp/contests/abc465/tasks/abc465_d
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    ll x,y,k;
    cin>>x>>y>>k;
    ll ans=0;
    while (x!=y)
    {
        if(x>y)x/=k;
        else y/=k;
        ans++;
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