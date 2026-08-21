/*
*created: 2026-08-06 at 23:10:15
*problem: A. Boss Fight, link: https://codeforces.com/contest/2252/problem/A
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;cin>>n;
    vector<int>cnt(1001,0);
    int S=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        cnt[a]++;
        S+=a;
    }
    auto mx=max_element(cnt.begin(),cnt.end());
    int c = *mx, v=mx-cnt.begin();
    if(c>n-c+2)S-=(2*c-n-2)*v;
    cout<<S<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}