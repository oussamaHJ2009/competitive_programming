/*
*created: 2026-08-11 at 19:44:02
*problem: E. Maximum Subarray Sum, link: https://codeforces.com/group/lRRb3iToWJ/contest/659962/problem/E
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    ll mn=0;
    ll ans = -1e9;
    ll s=0;
    for(int i=0;i<n;i++){
        ll a;cin>>a;
        s+=a;
        ans=max(s-mn,ans);
        mn=min(s,mn);
    }
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}