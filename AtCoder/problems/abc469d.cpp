/*
*created: 2026-08-01 at 20:51:28
*problem: The Big Two, link: https://atcoder.jp/contests/abc469/tasks/abc469_d
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>g(m);
    for(auto &[a,b]:g){
        cin>>a>>b;
    }
    int ans=0;
    int x=g[0].first;
    int c=0;
    vector<int>cnt(n+1,0);
    for(auto [a,b]:g){
        if(a!=x&&b!=x)cnt[a]++,cnt[b]++,c++;
    }
    for(int i=1;i<=n;i++)if(cnt[i]==c && i!=x)ans++;
    
    x=g[0].second;
    c=0;
    cnt.assign(n+1,0);
    for(auto [a,b]:g){
        if(a!=x&&b!=x)cnt[a]++,cnt[b]++,c++;
    }
    for(int i=1;i<=n;i++)if(cnt[i]==c && i!=g[0].first && i!=x)ans++;
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}