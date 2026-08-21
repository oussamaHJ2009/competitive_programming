#include <bits/stdc++.h>
#define f first
#define s second

using ll = long long;

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

void solve()
{
    int N;
    cin >> N;
    vector<pair<ll, ll>> P(N);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i].f >> P[i].s;
    }
    sort(P.begin(), P.end());
    ll ans = 0;
    vector<ll>B(N+1,0);
    for (int i = 0; i < N; i++)
        B[i+1]=P[i].s + B[i];
    
    ll mx = INT64_MIN;
    for (int i = 0; i < N; i++)
    {
        mx=max(mx,P[i].f - B[i]);
        ans = max(mx-P[i].f+B[i+1],ans);
    }

    cout << ans << '\n';
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