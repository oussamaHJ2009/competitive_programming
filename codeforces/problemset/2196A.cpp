#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    ll p,q;
    cin>>p>>q;
    ll k = 3*p - 2*q;
    if(k>=0 && k<=p && k<q && (p-k)*3 == (q-k)*2)cout<<"Bob";
    else cout<<"Alice";
    cout<<'\n';
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