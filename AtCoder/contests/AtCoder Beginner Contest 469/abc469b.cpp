/*
*created: 2026-08-01 at 13:02:54
*problem: Isolated Seats, link: https://atcoder.jp/contests/abc469/tasks/abc469_b
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;cin>>n;string s;cin>>s;
    int ans=0;
    for(int i=0;i<n;i++){
        if((!i || s[i-1]=='x') && s[i]=='x' && (i==n-1 || s[i+1]=='x'))ans++;
    }
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}