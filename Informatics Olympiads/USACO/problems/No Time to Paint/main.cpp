// just think and proof your idea clearly before touching the keyboard 
// write clean code simplifie your code before writing it
// genuinly there is a way simpler solution

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

vector<int> cnt[26];
int lst[26];

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> pre(n, 0), suf(n, 0);

    fill(cnt, cnt + 26, vector<int>(n, 0));
    fill(lst, lst + 26, -1);

    pre[0] = 1;
    cnt[s[0] - 'A'][0]++;
    lst[s[0] - 'A'] = 0;

    for (int i = 1; i < n; i++)
    {
        int c = 0;
        for (int ch = 0; ch < 26; ch++)
            cnt[ch][i] = cnt[ch][i - 1] + (ch == s[i] - 'A');

        if (lst[s[i] - 'A'] != -1)
            for (int ch = 0; ch < s[i] - 'A'; ch++)
                c += cnt[ch][i] - cnt[ch][lst[s[i] - 'A']];

        pre[i] = pre[i - 1] + (c != 0 || cnt[s[i] - 'A'][i - 1] == 0);

        lst[s[i] - 'A'] = i;
    }

    fill(cnt, cnt + 26, vector<int>(n, 0));
    fill(lst, lst + 26, -1);

    suf[n - 1] = 1;
    cnt[s[n - 1] - 'A'][n - 1]++;
    lst[s[n - 1] - 'A'] = n - 1;

    for (int i = n - 2; i >= 0; i--)
    {
        int c = 0;
        for (int ch = 0; ch < 26; ch++)
            cnt[ch][i] = cnt[ch][i + 1] + (ch == s[i] - 'A');

        if (lst[s[i] - 'A'] != -1)
            for (int ch = 0; ch < s[i] - 'A'; ch++)
                c += cnt[ch][i] - cnt[ch][lst[s[i] - 'A']];

        suf[i] = suf[i + 1] + (c != 0 || cnt[s[i] - 'A'][i + 1] == 0);

        lst[s[i] - 'A'] = i;
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