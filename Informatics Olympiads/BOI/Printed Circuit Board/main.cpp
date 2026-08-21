#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i].first >> x[i].second;
    }
    sort(x.begin(), x.end(),greater<pair<int,int>>());
    vector<int> dp;
    for (int i = 0; i < n; i++)
    {
        int l = upper_bound(dp.begin(), dp.end(), x[i].second) - dp.begin();
        if(l==dp.size())dp.push_back(x[i].second);
        else dp[l]=x[i].second;
    }
    cout<<dp.size()<<'\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}