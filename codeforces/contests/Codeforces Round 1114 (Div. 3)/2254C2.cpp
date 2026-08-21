/*
*created: 2026-08-04 at 16:32:31
*problem: F. Whiplash, link: https://codeforces.com/contest/2254/problem/F
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    string a,b;
    cin>>n>>a>>b;
    ll ans=0;
    for(ll st=0;st<2;st++){
        vector<ll>p1,p2;
        for(ll i=st;i<n;i+=2){
            if(a[i]=='1')p1.push_back(i);
            if(b[i]=='1')p2.push_back(i);
        }
        if(p1.size()!=p2.size()){
            cout<<"-1\n";
            return;
        }
        for(ll i=0;i<p1.size();i++){
            ans+=abs(p1[i]-p2[i]);
        }
    }
    cout<<ans/2<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}