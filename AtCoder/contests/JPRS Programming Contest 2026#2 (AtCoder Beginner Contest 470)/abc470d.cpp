/*
*created: 2026-08-08 at 13:00:08
*problem: Inverse and Swap, link: https://atcoder.jp/contests/abc470/tasks/abc470_d
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,Q;
    cin>>n>>Q;
    vector<int>p(n);
    for(int i=0;i<n;i++)cin>>p[i];
    int c=0;
    while(Q--){
        int t;cin>>t;
        if(t==1){
            int u,v;cin>>u>>v;
            if(c){
                
            }
            swap(p[u],p[v]);
        }else{
            c++;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}