/*
*created: 2026-08-15 at 13:00:06
*problem: Cookies and Greedy Takahashi, link: https://atcoder.jp/contests/abc471/tasks/abc471_c
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll>a(n+1,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    // for(auto x:a)cerr<<x<<" ";
    int cur = lower_bound(a.begin(),a.end(),0) - a.begin();
    // cerr<<cur<<'\n';
    int l=cur-1,r=cur+1;
    ll ans=0;
    while(r<=n && l>=0){
        // cerr<<l<<' '<<r<<'\n'; 
        if(abs(a[cur]-a[l])>abs(a[r]-a[cur])){
            ans+=abs(a[r]-a[cur]);
            cur=r;r++;
        }else{
            ans+=abs(a[cur] - a[l]);
            cur=l;l--;
        }
    }
    if(r<=n)
        ans+=abs(a[n]-a[cur]);
    if(l>=0)ans+=abs(a[cur] - a[0]);
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}