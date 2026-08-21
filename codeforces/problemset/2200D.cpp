#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        if (i <= x || i > y) a.push_back(j);
        else b.push_back(j);
    }

    // solve
    if (!b.empty()) rotate(b.begin(), min_element(b.begin(), b.end()), b.end());
    int m = b.empty() ? -1 : b[0];
    auto it = a.begin();
    while (it != a.end() && *it < m) it++;
    a.insert(it, b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n-1];
    }
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}