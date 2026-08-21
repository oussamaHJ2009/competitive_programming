/*
 *created: 2026-07-30 at 15:40:34
 *problem: C. Covered Points Count, link: https://codeforces.com/problemset/problem/1000/C
 *author: a human
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct seg{ll l, r;};

void solve()
{
    int n;
    cin >> n;
    vector<seg> s(n);
    vector<ll> pt{0};
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].l >> s[i].r;
        pt.push_back(s[i].l);
        pt.push_back(s[i].r + 1);
    }
    sort(pt.begin(), pt.end());
    pt.erase(unique(pt.begin(), pt.end()), pt.end());
    int m = pt.size();
    vector<int> cnt(m, 0);
    for (int i = 0; i < n; i++)
    {
        int ptl = lower_bound(pt.begin(), pt.end(), s[i].l) - pt.begin(),
            ptr = lower_bound(pt.begin(), pt.end(), s[i].r + 1) - pt.begin();
        cnt[ptl]++, cnt[ptr]--;
    }
    for (int i = 1; i < m; i++)
        cnt[i] += cnt[i - 1];
    vector<ll> ans(n + 1, 0);
    for (int i = 0; i < m - 1; i++)
    {
        ans[cnt[i]] += pt[i + 1] - pt[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}