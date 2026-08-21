//problem link: https://codeforces.com/gym/102951/problem/D
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,q;
    cin>>n>>q;
    map<ll,ll>comp;
    comp[-1]=0;
    for (int i = 0; i < n; i++)
    {
        ll l,r,v;
        cin>>l>>r>>v;
        comp[l]+=v;comp[r]-=v;
    }
    ll lst=0;
    vector<ll>c,a,p;
    for (auto [pt,v]:comp)
    {
        c.push_back(pt);
        a.push_back(v);
    }
    c.push_back(1e9+1);
    a.push_back(0);
    
    int pts=a.size();
    for (int i = 1; i < pts; i++)a[i]+=a[i-1];
    ll pre=0;
    for (int i = 1; i < pts; i++){
        p.push_back(pre);
        pre+=(c[i]-c[i-1])*a[i-1];
    }

    while (q--)
    {
        int l,r;
        cin>>l>>r;
        int lo=upper_bound(c.begin(),c.end(),l)-c.begin()-1;
        int hi=upper_bound(c.begin(),c.end(),r)-c.begin()-1;
        ll ans=p[hi]-p[lo]+a[hi]*(r-c[hi]) - a[lo]*(l-c[lo]);
        cout<<ans<<'\n';
    }
    
    
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