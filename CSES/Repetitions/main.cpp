#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    string s;
    cin >> s;
    int ans = 1, seg = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[i - 1])
        {
            ans = max(seg, ans);
            seg=1;
        }else seg++;
    }
    ans=max(ans,seg);
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}