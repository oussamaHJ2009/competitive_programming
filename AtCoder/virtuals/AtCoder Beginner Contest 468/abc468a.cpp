/*
*created: 2026-08-11 at 14:34:54
*problem: Maximal Value, link: https://atcoder.jp/contests/abc468/tasks/abc468_a
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int ans=0;
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-2;i++){
        if(a[i]<a[i+1] && a[i+1]>a[i+2])ans++;
    }
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}