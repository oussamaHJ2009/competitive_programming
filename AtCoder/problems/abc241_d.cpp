#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int q;
    cin >> q;
    multiset<ll> s;
    while (q--) {
        int ch;
        cin >> ch;
        if (ch == 1) {
            ll x;
            cin >> x;
            s.insert(x);
        }
        else if (ch == 2) {
            ll x,k;
            cin >> x >> k;
            auto it = s.upper_bound(x);
            bool flag = true;
            for (int i = 0; i < k; i++) {
                if (it == s.begin()) {
                    flag = false;
                    break;
                }
                it--;
            }
            if (flag) cout << *it << "\n";
            else cout << "-1\n";
        }
        else if (ch == 3) {
            ll x;
            int k;
            cin >> x >> k;
            auto it = s.lower_bound(x);
            bool flag = true;
            for (int i = 0; i < k - 1; i++) {
                if (it == s.end()) {
                    flag = false;
                    break;
                }
                it++;
            }
            if (it == s.end()) flag = false;
            if (flag) cout << *it << "\n";
            else cout << "-1\n";
        }
    }
}