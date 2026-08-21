#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int spf[N], cnt[N];

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    for (int i = 0, b; i < n; i++) cin >> b;

    auto get_primes = [](int x) {
        vector<int> p;
        while(x > 1) {
            int P = spf[x];
            p.push_back(P);
            while (x % P == 0) x /= P;
        }
        return p;
    };

    int ans = 2;
    for (int x : a) 
        for (int p : get_primes(x)) if (++cnt[p] >= 2) ans = 0;

    if (ans > 0) {
        for (int x : a) {
            for (int p : get_primes(x)) cnt[p]--;
            for (int p : get_primes(x + 1)) if (cnt[p]) ans = 1;
            for (int p : get_primes(x)) cnt[p]++;
        }
    }

    cout << ans << "\n";
    for (int x : a) for (int p : get_primes(x)) cnt[p] = 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    iota(spf, spf + N, 0);
    for (int i = 2; i*i < N; i++)
        if (spf[i] == i)
            for (int j = i*i; j < N; j += i)
                if (spf[j] == j) spf[j] = i;

    int t; cin >> t;
    while (t--) solve();
}