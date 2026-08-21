#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin>>n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    sort(a.begin(), a.end());
    map<ll, ll> cnt;
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
    }
    
    vector<ull> dp(a[n - 1] + 1, 0);
    dp[1] = cnt[1];
    for (int i = 2; i <= a[n - 1]; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
    }
    cout<<dp[a[n - 1]];
    
    return 0;
}