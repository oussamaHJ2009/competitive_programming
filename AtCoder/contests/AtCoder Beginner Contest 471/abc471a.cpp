/*
*created: 2026-08-15 at 13:00:06
*problem: Nine or Nein, link: https://atcoder.jp/contests/abc471/tasks/abc471_a
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a,b;
    cin>>a>>b;
    if(a+b==9 || a-b==9 || a*b==9||(a/b==9 && a%b==0))cout<<"Nine\n";
    else cout<<"Nein\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}