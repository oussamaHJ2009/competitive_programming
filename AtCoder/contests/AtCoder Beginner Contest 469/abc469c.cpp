/*
*created: 2026-08-01 at 13:02:54
*problem: Cantrip, link: https://atcoder.jp/contests/abc469/tasks/abc469_c
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;cin>>n>>s;
    vector<int>p(n+1);
    p[0]=0;
    for(int i=0;i<n;i++)p[i+1]=p[i]+(s[i]=='o');
    for(int k=1;k<=n;k++){
        int ans=k,r=k,l=0,c;
        while(r<=n && r-l>0){
            c=p[r]-p[l];
            l=r,r+=c;
            ans+=min(n,r)-l;
        }
        cout<<ans<<'\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}