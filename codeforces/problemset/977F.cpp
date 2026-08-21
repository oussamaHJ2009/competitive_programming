/*
 *created: 2026-07-29 at 21:06:58
 *problem: F. Consecutive Subsequence, link: https://codeforces.com/contest/977/problem/F
 *author: a human
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a)
        cin >> it;
    map<int, int> dp;
    int mx = 0;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
        if (dp[mx] < dp[a[i]])
            mx = a[i];
    }
    int cur = mx - dp[mx] + 1;
    cout<<dp[mx]<<'\n';
    for (int i = 0; i < n; i++)
    {
        if(a[i]==cur)cout<<i+1<<' ',cur++;
    }
    
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}