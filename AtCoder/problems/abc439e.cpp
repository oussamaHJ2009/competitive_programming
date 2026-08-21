/*
 *created: 2026-07-30 at 17:12:49
 *problem: Kite, link: https://atcoder.jp/contests/abc439/tasks/abc439_e
 *author: a human
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.begin(), ab.end(), cmp);
    vector<int> dp;
    for (auto [_, i] : ab)
    {
        int l = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
        if (l == (int)dp.size())
            dp.push_back(i);
        else
            dp[l] = i;
    }
    cout << dp.size() << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}