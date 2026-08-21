// problem link: https://codeforces.com/problemset/problem/2242/C
// authored by a human (i guess?)

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> f;
    ll ans = 0, x, lst = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x != lst)
        {
            f.push_back(1);
            lst = x;
        }
        else
            f.back()++;
    }
    sort(f.begin(), f.end());
    int c = 1, r = 0;
    int m = f.size();
    

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}