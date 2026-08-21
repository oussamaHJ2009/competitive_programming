/*
*created: 2026-08-07 at 15:35:09
*problem: A. The Best Card, link: https://codeforces.com/contest/2253/problem/A
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        if((n+1)%i==0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}