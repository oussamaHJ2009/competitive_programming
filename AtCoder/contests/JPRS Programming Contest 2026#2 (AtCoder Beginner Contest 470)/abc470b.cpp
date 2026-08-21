/*
*created: 2026-08-08 at 13:00:07
*problem: Monocolor, link: https://atcoder.jp/contests/abc470/tasks/abc470_b
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>c(n+1,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        c[x]++;
    }
    int f=*max_element(c.begin(),c.end());
    cout<<n-f;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}