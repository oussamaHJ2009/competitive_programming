/*
*created: 2026-08-11 at 14:34:54
*problem: Between P and Q, link: https://atcoder.jp/contests/abc468/tasks/abc468_c
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>p(n),q(n),t(n);
    iota(t.begin(),t.end(),1);
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=0;i<n;i++)cin>>q[i];
    ll ans=0;
    do{
        if(t>p && t<q)ans++;
    }while (next_permutation(t.begin(),t.end()));
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}