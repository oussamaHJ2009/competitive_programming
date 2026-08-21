#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll ans=0;
    ll g=a[0];
    for (int i = 1; i < n; i++)
    {
        g=gcd(g,a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        ans+=a[i]/g - 1;
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}