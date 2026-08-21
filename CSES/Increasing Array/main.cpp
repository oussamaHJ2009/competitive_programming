#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<ll>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll ans=0;
    ll mx=0;
    for (int i = 0; i < n; i++)
    {
        mx=max(mx,a[i]);
        ans+=mx-a[i];
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