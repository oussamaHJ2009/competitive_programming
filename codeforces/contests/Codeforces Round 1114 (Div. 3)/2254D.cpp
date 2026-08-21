/*
*created: 2026-08-04 at 16:34:57
*problem: D. Silhouette, link: https://codeforces.com/contest/2254/problem/D
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin>>n;
    vector<ll>b(n);
    for(ll i=0;i<n;i++)cin>>b[i];
    vector<ll>cc=b;
    sort(cc.begin(),cc.end());
    vector<ll>cp1 = cc;
    cc.erase(unique(cc.begin(),cc.end()), cc.end());
    vector<ll>a(n,0);
    for(ll i=0;i<n;i++){
        auto lo = lower_bound(cp1.begin(),cp1.end(), b[i]);
        auto up = upper_bound(cp1.begin(),cp1.end(), b[i]);
        if(up!=cp1.end()){
            a[i]=(*up-*lo);
            ll cnt = up-lo;
            if(a[i]%cnt){
                cout<<"-1\n";
                return;
            }
            a[i]/=cnt;
        }
    }
    ll mx = *max_element(a.begin(),a.end());
    for(ll i=0;i<n;i++)if(a[i]==0)a[i]=mx+1;
    vector<ll>cp=a;
    sort(cp.begin(),cp.end());
    vector<ll>cc2=cp;
    cc2.erase(unique(cc2.begin(),cc2.end()),cc2.end());
    ll s=0;
    // cerr<<"cc:";
    // for(auto x:cc)cerr<<x<<' ';
    // cerr<<'\n';
    // cerr<<"cc2:";
    // for(auto x:cc2)cerr<<x<<' ';
    // cerr<<'\n';
    // cerr<<"a:";
    // for(auto x:a)cerr<<x<<' ';
    // cerr<<'\n';
    // cerr<<"cp:";
    // for(auto x:cp)cerr<<x<<' ';
    // cerr<<'\n';
    for(ll i=0;i<cc2.size();i++){
        if(cc[i]!=s){
            cout<<"-1\n";return;
        }
        ll cnt=upper_bound(cp.begin(),cp.end(),cc2[i]) - lower_bound(cp.begin(),cp.end(),cc2[i]);
        s+=cnt*cc2[i];
    }
    for(auto x:a)cout<<x<<' ';
    cout<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--){
        solve();
        // if(t)cerr<<"####################################\n";
    }
    return 0;
}