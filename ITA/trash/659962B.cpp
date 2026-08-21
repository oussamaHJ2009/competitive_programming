/*
*created: 2026-08-11 at 19:22:03
*problem: B. Promo, link: https://codeforces.com/group/lRRb3iToWJ/contest/659962/problem/B
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll>a(n);
    vector<ll>pre(n+1,0);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        pre[i+1]=pre[i]+a[i];
    }
    sort(a.begin(),a.end(),greater<ll>());
    for(ll i=0;i<n;i++){
        pre[i+1]=pre[i]+a[i];
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        cout<<pre[x] - pre[x-y]<<'\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}