/*
*created: 2026-08-04 at 16:12:25
*problem: C1. Marenol (easy version), link: https://codeforces.com/contest/2254/problem/C1
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    multiset<ll>b;
    cin>>n;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        b.insert(x);
    }
    vector<ll>a;
    ll d=1;
    while(!b.empty()){
        auto it = b.lower_bound(d);
        if(it == b.end()){
            cout<<"-1\n";return;
        }
        if(a.empty())a.push_back(*it);
        else a.push_back(*it + a.back());
        b.erase(it);
        d=1-a.back();
    }
    for(auto x:a)cout<<x<<' ';
    cout<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}