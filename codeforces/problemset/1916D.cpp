#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        if (n == 2) {
            cout << stoll(s) << '\n';
            continue;
        }

        ll ans = 1000;
            for (int i = 0; i < n - 1; ++i) {
            vector<int> a;
            a.reserve(n-1);
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    int val = (s[j]-'0')*10 + (s[j+1]-'0');
                    a.push_back(val);
                    ++j;
                } else {
                    a.push_back(s[j]-'0');
                }
            }

            bool hasZero = false;
            bool allOnes = true;
            ll sumNotOne = 0;
            for (int x : a) {
                if (x == 0) hasZero = true;
                if (x != 1) allOnes = false;
                if (x != 1) sumNotOne += x;
            }

            ll cur;
            if (hasZero) {
                cur = 0;
            } else if (allOnes) {
                cur = 1;
            } else {
                cur = sumNotOne;
            }

            ans = min(ans, cur);
        }

        cout << ans << '\n';
    }
    return 0;
}
