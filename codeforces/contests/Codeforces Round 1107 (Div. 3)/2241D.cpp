//problem link: https://codeforces.com/contest/2241/problem/D
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    ll n;
    cin>>n;
    vector<ll>a(n),b(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    for (ll i = n - 1; i > 0; i--)
    {
        if(a[i]>b[i])a[i-1]+=a[i]-b[i];
    }
    if(a[0]>b[0])cout<<"NO\n";
    else cout<<"YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}