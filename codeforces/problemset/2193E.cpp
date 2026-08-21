#include <bits/stdc++.h>
 
using namespace std;
const int maxn = 1'000'012;
 
int a[maxn], dp[maxn];
int n, q;
 
void solve() {
    cin >> n;
 
    for(int i = 1; i <= n; i++) {
        dp[i] = 1e9;
    }
    for(int i = 1; i <= n;i++) {
        cin >> a[i];
        dp[a[i]] = 1;
    }
 
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            dp[j] = min(dp[j], dp[i] + dp[j / i]);
        }
    }
 
    for(int i = 1; i <= n; i++) {
        if(dp[i] == 1e9) {
            dp[i] = -1;
        }
        cout << dp[i] << " \n"[i == n];
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}