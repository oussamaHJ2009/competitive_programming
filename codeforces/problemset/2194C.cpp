#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<string> a(k);
        for (int i = 0; i < k; ++i) cin >> a[i];

        // build masks for columns
        vector<int> mask(n, 0);
        for (int j = 0; j < n; ++j) {
            int m = 0;
            for (int i = 0; i < k; ++i) {
                m |= 1 << (a[i][j] - 'a');
            }
            mask[j] = m;
        }

        // compute divisors of n sorted ascending
        vector<int> divs;
        for (int d = 1; d * d <= n; ++d) {
            if (n % d == 0) {
                divs.push_back(d);
                if (d != n / d) divs.push_back(n / d);
            }
        }
        sort(divs.begin(), divs.end());

        string ans(n, '?');
        bool found = false;
        for (int d : divs) {
            bool ok = true;
            string cand(n, '?');
            for (int r = 0; r < d && ok; ++r) {
                int inter = (1 << 26) - 1; // all bits set
                for (int j = r; j < n; j += d) inter &= mask[j];
                if (inter == 0) { ok = false; break; }
                // choose lowest set bit
                int bit = __builtin_ctz(inter);
                char ch = char('a' + bit);
                for (int j = r; j < n; j += d) cand[j] = ch;
            }
            if (ok) {
                ans = move(cand);
                found = true;
                break;
            }
        }
        // by problem statement there is always an answer; but just in case:
        if (!found) {
            // fallback: pick any available letter per column
            for (int j = 0; j < n; ++j) {
                int m = mask[j];
                int bit = __builtin_ctz(m);
                ans[j] = char('a' + bit);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
