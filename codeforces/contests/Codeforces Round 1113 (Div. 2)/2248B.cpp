/*
*created: 2026-08-01 at 15:50:17
*problem: B. Merge to Match, link: https://codeforces.com/contest/2248/problem/B
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    if(n<2*m){cout<<"NO\n";return;}
    bool y=1;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<m;i++){
        if(a[i]>=b[i] || b[i]>=a[n-m + i])y=0;
    }
    cout<<(y?"YES":"NO")<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}