//problem link: https://codeforces.com/contest/2245/problem/B
//authored by a human (i guess?)

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll c;
    cin>>n>>c;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll s=0;
    sort(a.begin(),a.end());
    int l=0,r=n-1;
    while(l<=r){
        s+=a[r]-c;
        r--;
        if(a[l]<=c)l++;
    }
    cout<<s<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}