#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    if (a.length() < b.length()) {
        sort(a.rbegin(), a.rend());
        cout << a << endl;
        return 0;
    }
    vector<int> cnt(10, 0);
    for (char c : a) {
        cnt[c - '0']++;
    }

    string res = "";
    int n = a.length();

    for (int i = 0; i < n; ++i) {
        for (int d = 9; d >= 0; --d) {
            if (cnt[d] > 0) {
                cnt[d]--;
                string current_attempt = res + (char)(d + '0');
                string suffix = "";
                for (int next_d = 0; next_d <= 9; ++next_d) {
                    for (int k = 0; k < cnt[next_d]; ++k) {
                        suffix += (char)(next_d + '0');
                    }
                }                
                string full_num = current_attempt + suffix;
                if (full_num <= b) {
                    res += (char)(d + '0');
                    goto next_pos;
                } else {
                    cnt[d]++;
                }
            }
        }
        next_pos:;
    }

    cout << res << endl;

    return 0;
}