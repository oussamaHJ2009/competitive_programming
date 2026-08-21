/*
*created: 2026-08-09 at 17:34:12
*problem: C. Hot Potatoes at the Fairy Warehouse, link: https://codeforces.com/contest/2256/problem/C
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,k;
    string s;
    cin>>n>>k>>s;
    vector<pair<int,int>>sp;
    for(int i=0;i<2*n;i++){
        if(s[i]=='1' && s[(i+1)%(2*n)]=='0')sp.push_back({i,(i+1)%(2*n)});
    }
    for(auto [u,v]:sp)swap(s[u],s[v]);
    int sc[2]{0,0};
    for(int i=0;i<2*n;i++){
        if(s[i]=='1')sc[i&1]++;
    }
    cout<<sc[1]<<' '<<sc[0]<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}