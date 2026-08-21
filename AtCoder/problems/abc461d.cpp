// problem link: https://atcoder.jp/contests/abc461/tasks/abc461_d
// written by a rando

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    ll h, w, k;
    cin >> h >> w >> k;
    vector<vector<ll>> a(h, vector<ll>(w));
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    }
    vector<vector<ll>> ver(w, vector<ll>(h + 1, 0));
    for (ll i = 0; i < w; i++)
    {
        for (ll j = 1; j <= h; j++)
        {
            ver[i][j] = ver[i][j - 1] + a[j - 1][i];
        }
    }
    ll ans = 0;
    for (ll top = 0; top < h; top++)
    {
        for (ll bot = top; bot < h; bot++)
        {
            vector<ll> B(w);
            for (ll i = 0; i < w; i++)
            {
                B[i] = ver[i][bot + 1] - ver[i][top];
            }
            ll lk=0,lk_=0;
            ll s1=0,s2=0;
            for (ll r = 0; r < w; r++)
            {
                s1+=B[r];
                s2+=B[r];
                while (s1>k)
                {
                    s1-=B[lk];
                    lk++;
                }
                while (s2>=k && lk_<=r)
                {
                    s2-=B[lk_];
                    lk_++;
                }
                ans+=lk_-lk;
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}