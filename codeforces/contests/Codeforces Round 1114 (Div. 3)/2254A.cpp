/*
*created: 2026-08-04 at 15:35:05
*problem: A. Riptide, link: https://codeforces.com/contest/2254/problem/A
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    cout<<min({(a[2]-a[0])/2 , a[2]-a[1], a[1]-a[0]})<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}