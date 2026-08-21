/*
*created: 2026-08-03 at 20:28:06
*problem: Unusual-Constraint Knapsack, link: https://atcoder.jp/contests/arc223/tasks/arc223_a
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll W;
    cin>>n>>W;
    vector<ll>w(n),v(n);
    vector<ll>s(n+1,0);
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
        s[i+1]=v[i]+s[i];
    }
    ll ans=0,S=0;
    for(int i=n-1;i>=0;i--){
        if(W>=w[i]){
            ans=max(ans,S+s[i]);
            S+=v[i];
            W-=w[i];
        }
    }
    cout<<max(ans,S)<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}