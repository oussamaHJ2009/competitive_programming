#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<ll>p(n);
    for(int i=0;i<n;i++)cin>>p[i];
    ll mn=0;
    ll ans=INT32_MIN;
    for(int i=1;i<n;i++){
        p[i]+=p[i-1];
    }
    for (int i = 0; i < n; i++)
    {
        ans=max(ans,p[i]-mn);
        mn=min(mn,p[i]);
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