/*
*created: 2026-08-09 at 17:10:46
*problem: A. Three Numbers on the Blackboard, link: https://codeforces.com/contest/2256/problem/A
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int x[3];
    for(int i=0;i<3;i++)cin>>x[i];
    sort(x,x+3);
    x[2]=min(x[0]+x[1],x[2]);
    cout<<x[2]-x[0]<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}