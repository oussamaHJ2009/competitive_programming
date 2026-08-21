#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    ll n,m;
    cin>>n>>m;
    string s,ss;
    for (ll i = 0; i < m; i++)
    {
        cin>>ss;s+=ss;
    }
    ll ans=0;
    vector<ll>f;
    ll seg=1;
    for (ll i = 1; i < n; i++)
    {
        if(s[i]==s[i-1])seg++;
        else {
            f.push_back(seg);
            seg=1;
        }
    }
    f.push_back(seg);
    sort(f.begin()+1,f.end(),greater<ll>());
    for (ll i = 0; i < min(m,(ll)f.size()); i++)ans+=f[i];
    
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}