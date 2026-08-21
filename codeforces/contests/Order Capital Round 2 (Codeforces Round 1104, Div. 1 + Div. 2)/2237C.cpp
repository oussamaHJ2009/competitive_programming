//problem link: https://codeforces.com/contest/2237/problem/C
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<ll>a(n);
    for(auto &it:a)cin>>it;
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]<ans)ans+=a[i];
        else ans=a[i];
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}