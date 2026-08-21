#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string a; int n; cin >> a >> n;
    ll v = stoll(a); int sz = a.size();
    vector<char> d(n); vector<bool> has(10, 0);
    for (int i = 0; i < n; ++i) { cin >> d[i]; has[d[i]-'0'] = 1; }
    
    ll ans = LLONG_MAX;
    if (sz > 1) ans = min(ans, abs(v - stoll(string(sz - 1, d[n - 1]))));
    if (d[0] != '0') ans = min(ans, abs(v - stoll(string(sz + 1, d[0]))));
    else if (n > 1)  ans = min(ans, abs(v - stoll(d[1] + string(sz, d[0]))));
    
    string pref = "";
    for (int i = 0; i < sz; i++) {
        for (char c : d) {
            ans = min(ans, abs(v - stoll(pref + c + string(sz - i - 1, d[n - 1]))));
            ans = min(ans, abs(v - stoll(pref + c + string(sz - i - 1, d[0]))));
        }
        if (!has[a[i]-'0']) break;
        pref += a[i];
    }
    if (pref.size() == sz) ans = 0;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; if (cin >> t) while (t--) solve();
}