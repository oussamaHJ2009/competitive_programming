/*
*created: 2026-08-09 at 14:35:07
*problem: Square Corner Packing, link: https://atcoder.jp/contests/arc226/tasks/arc226_c
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int h,w;
    cin>>h>>w;
    vector<tuple<int,int,int>>ops;
    for(int i=2;i<=h;i+=2){
        for(int j = 1;j<w;j+=2){
            ops.push_back({i,j,1});
        }
    }
    cout<<ops.size()<<'\n';
    for(auto [r,c,j]:ops){
        cout<<r<<' '<<c<<' '<<j<<'\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}