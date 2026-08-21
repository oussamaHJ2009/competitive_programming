/*
*created: 2026-08-08 at 15:12:16
*problem: Inverse and Swap, link: https://atcoder.jp/contests/abc470/tasks/abc470_d
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int>p[2];
    p[0].assign(n,0);
    p[1].assign(n,0);
    for(int i=0;i<n;i++){
        cin>>p[0][i];
        p[0][i]--;
        p[1][p[0][i]]=i;
    }
    int id=0;
    while(q--){
        int t;cin>>t;
        if(t==1){
            int x,y;
            cin>>x>>y;
            x--;y--;
            swap(p[id^1][p[id][x]],p[id^1][p[id][y]]);
            swap(p[id][x],p[id][y]);
        }else{
            id^=1;
        }
    }

    for(int i=0;i<n;i++){
        cout<<p[id][i]+1<<' ';
    }
    cout<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}