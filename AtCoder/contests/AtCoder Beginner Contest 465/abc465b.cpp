//problem link: https://atcoder.jp/contests/abc465/tasks/abc465_b
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int x,y,l,r,a,b;
    cin>>x>>y>>l>>r>>a>>b;
    int ans=0;
    for (int tt = a; tt < b; tt++)
    {
        if(tt<r && tt>=l)ans+=x;
        else ans+=y;
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}