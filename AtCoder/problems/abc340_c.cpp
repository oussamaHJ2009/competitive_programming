#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
map<ll,ll>m;
ll f(ll n) {
    if(m[n])return m[n];
    m[n] = n == 1 ? 0 : f(n / 2) + f((n + 1) / 2) + n;
    return m[n];
}

void solve() {
    ll n;
    cin>>n;
    cout<<f(n)<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}