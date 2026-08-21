#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>g(n);
    for (int i = 0; i < n; i++)
    {
        cin>>g[i];
    }
    sort(g.begin(),g.end(),greater<int>());
    ll ans=0;
    for (int i = 0; i < n; i+=2)
    {
        ans+=g[i];
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