/*
*created: 2026-08-11 at 19:54:38
*problem: R. Blank Space, link: https://codeforces.com/group/lRRb3iToWJ/contest/659962/problem/R
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    int cur=0;
    int ans=0;
    while(n--){
        int a;cin>>a;
        if(a)ans=max(ans,cur),cur=0;
        else cur++;
    }
    ans=max(ans,cur);
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}