/*
*created: 2026-08-11 at 19:30:41
*problem: C. Calculating Function, link: https://codeforces.com/group/lRRb3iToWJ/contest/659962/problem/C
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin>>n;
    ll ans=n/2;
    if(n%2)ans-=n;
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}