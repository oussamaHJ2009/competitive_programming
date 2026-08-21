#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty())
    {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pre(n), suf(n);
    vector<int> dp(26, -1);
    pre[0] = 1;
    dp[s[0] - 'A'] = 0;
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + (dp[s[i] - 'A'] == -1 ? 1 : dp[s[i] - 'A']);
        dp[s[i] - 'A'] = 0;
        for (int ch = s[i] - 'A' + 1; ch < 26; ch++)
            if (dp[ch] != -1)
                dp[ch] = 1;
    }
    suf[n-1] = 1;
    dp.assign(26, -1);
    dp[s[n - 1] - 'A'] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = suf[i + 1] + (dp[s[i] - 'A'] == -1 ? 1 : dp[s[i] - 'A']);
        dp[s[i] - 'A'] = 0;
        for (int ch = s[i] - 'A' + 1; ch < 26; ch++)
            if (dp[ch] != -1)
                dp[ch] = 1;
    }

    for (int qry = 0; qry < q; qry++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int ans = 0;
        if (r < n - 1)
            ans += suf[r + 1];
        if (l > 0)
            ans += pre[l - 1];
        cout << ans << '\n';
    }
}

int main()
{
    setIO("");
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}