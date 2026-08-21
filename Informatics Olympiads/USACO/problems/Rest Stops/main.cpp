#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll int64_t

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
    ll L, N, rF, rB;
    cin >> L >> N >> rF >> rB;
    vector<pair<ll, ll>> stop(N);
    for (int i = 0; i < N; i++)
    {
        cin >> stop[i].s >> stop[i].f;
    }
    sort(stop.begin(), stop.end(), greater<pair<ll, ll>>());
    ll lst = 0;
    ll ans = 0;
    for (auto [c, x] : stop)
    {
        if (x > lst)
        {
            ll t = (x - lst) * (rF - rB);
            lst = x;
            ans += t * c;
        }
    }

    cout<<ans<<'\n';
}

int main()
{
    setIO("reststops");
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}