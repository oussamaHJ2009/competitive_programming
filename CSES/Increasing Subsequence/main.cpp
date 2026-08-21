#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9+1;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> lis(n + 1, INF);
    lis[0] = -INF;

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int l = upper_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
        if (lis[l - 1] < a[i])
        {
            lis[l] = a[i];
            ans = max(ans, l);
        }
    }
    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}