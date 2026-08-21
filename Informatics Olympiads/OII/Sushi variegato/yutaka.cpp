#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int taglia(int N, int V[]) {
    vector<long long> prefix(N + 1, 0);
    prefix[0] = 1;
    vector<int> last(1000001, -1);
    int l = 0;
    for (int i = 1; i <= N; i++) {
        if (last[V[i - 1]] >= l) {
            l = last[V[i - 1]] + 1;
        }
        last[V[i - 1]] = i - 1;
        long long dp_i = prefix[i - 1] - (l > 0 ? prefix[l - 1] : 0);
        dp_i = ((dp_i % MOD) + MOD) % MOD;
        prefix[i] = (prefix[i - 1] + dp_i) % MOD;
    }
    long long ans = (prefix[N] - prefix[N - 1] + MOD) % MOD;
    return (int)ans;
}