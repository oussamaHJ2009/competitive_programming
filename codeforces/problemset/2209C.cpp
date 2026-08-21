#include <bits/stdc++.h>
using namespace std;

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        if (ask(2 * i - 1, 2 * i)) {
            cout << "! " << 2 * i - 1 << endl;
            return;
        }
    }

    if (ask(1, 3)) {
        cout << "! 1" << endl;
    } else if (ask(1, 4)) {
        cout << "! 1" << endl;
    } else {
        cout << "! 2" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}