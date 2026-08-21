/*
*created: 2026-08-06 at 20:48:49
*problem: D. Array Replacement, link: https://codeforces.com/contest/2252/problem/D
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll>a(n),d(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i)d[i]=a[i]-a[i-1];
        else d[i]=a[i];
    }
    vector<pair<int,int>>rng;
    int l=1;
    for(int i=2;i<n;i++){
        if(abs(d[i])%2 != abs(d[i-1])%2){
            rng.push_back({l,i});
            l=i;
        }
    }
    rng.push_back({l,n});
    for(auto [l,r]:rng){
        sort(d.begin()+l,d.begin()+r);
    }
    cout<<d[0]<<' ';
    for(int i=1;i<n;i++){
        d[i]+=d[i-1];
        cout<<d[i]<<' ';
    }
    cout<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}