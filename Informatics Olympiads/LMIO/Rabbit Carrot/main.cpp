#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int lnds(vector<int> a)
{
    vector<int> dp;
    for (auto i : a)
    {
        if(i<0)continue;
        int l = upper_bound(dp.begin(), dp.end(), i) - dp.begin();
        if (l == (int)dp.size())
            dp.push_back(i);
        else
            dp[l] = i;
    }

    return dp.size();
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] -= (i+1) * m;
        a[i] = -a[i];
    }
    cout << n - lnds(a) << '\n';
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}