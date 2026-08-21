/*
*created: 2026-08-11 at 19:58:44
*problem: N. Two Buttons, link: https://codeforces.com/group/lRRb3iToWJ/contest/659962/problem/N
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    while(m>n){
        ans+=1+m%2;
        m+=m%2;
        m>>=1;
    }
    ans+=n-m;
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}