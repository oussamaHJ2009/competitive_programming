#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9 + 1;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp;
    for (auto x : a)
    {
        int l = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
        if (l == dp.size())
            dp.push_back(x);
        else
            dp[l] = x;
    }
    cout << dp.size() << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}