#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int count_digits(ll n) {
    if (n == 0) return 0;
    return to_string(n).length();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> pow10(11);
    pow10[0] = 1;
    for (int i = 1; i <= 10; ++i) pow10[i] = pow10[i - 1] * 10;
    
    vector<vector<ll>> P(11);
    for (int i = 0; i < 30; ++i) {
        ll val = 1LL << i;
        int d = count_digits(val);
        P[d].push_back(val);
    }
    
    vector<unordered_set<ll>> X(11);
    X[0].insert(0);

    vector<ll> all_good_integers;

    for (int k = 1; k <= 9; ++k) {
        for (int i = 1; i <= k; ++i) {
            for (ll x : X[k - i]) {
                for (ll p : P[i]) {
                    ll combined = x * pow10[i] + p;
                    X[k].insert(combined);
                }
            }
        }
        for (ll val : X[k]) {
            all_good_integers.push_back(val);
        }
    }
    sort(all_good_integers.begin(), all_good_integers.end());
    cout << all_good_integers[n - 1] << endl;

    return 0;
}