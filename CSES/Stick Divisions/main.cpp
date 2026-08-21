#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll k,n; cin>>k>>n;
    ll ans = 0;
    multiset<ll> s;
    for (ll i = 0; i < n; i++) {
        ll x; cin>>x;
        s.insert(x);
    }
    while(s.size() > 1) {
        auto x = s.begin();
        s.erase(x);
        auto y = s.begin();
        s.erase(y);
        ans += *x+*y;
        s.insert(*x+*y);
    }
    cout<<ans;

    return 0;

}