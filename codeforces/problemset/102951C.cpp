/*
 *created: 2026-07-29 at 21:25:46
 *problem: C. LCS on Permutations, link: https://codeforces.com/gym/102951/problem/C
 *author: a human
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int lis(vector<int> a)
{
    vector<int> dp;
    for (auto x : a)
    {
        int l = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
        if (l == dp.size())
            dp.push_back(x);
        else
            dp[l] = x;
    }
    return dp.size();
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x - 1] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b[i] = a[x - 1];
    }
    cout<<lis(b)<<'\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}