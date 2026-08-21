// problem link: https://codeforces.com/contest/2236/problem/D#
// written by a rando

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = int64_t;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), cnt(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(all(a));
    vector<int> w(n + 1, 0);
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(all(a), a[i]);
        if ((cnt[a[i]] & 1) && (it == a.end() || *it - a[i] > k))
            w[a[i]] = 1;
        if(w[a[i]]==0)ans=1;
    }
    cout<<(ans?"YES":"NO")<<'\n';
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