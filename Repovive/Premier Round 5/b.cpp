#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<ll>h(n);
    vector<ll>v(n);
    map<ll,ll>cnt;
    for (int i = 0; i < n; i++)
    {
        cin>>h[i];
        h[i]*=i+1;
        cnt[h[i]]++;
    }
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        v[i]*=i+1;
        ans+=cnt[v[i]];
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