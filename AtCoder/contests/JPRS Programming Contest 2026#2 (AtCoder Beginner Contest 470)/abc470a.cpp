/*
*created: 2026-08-08 at 13:00:07
*problem: Fizz, link: https://atcoder.jp/contests/abc470/tasks/abc470_a
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%3)cout<<i<<'\n';
        else cout<<"Fizz"<<'\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}