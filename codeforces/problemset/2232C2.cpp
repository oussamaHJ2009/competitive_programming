#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int n, x, s;
    cin >> n >> x >> s;

    string u;
    cin >> u;

    auto f = [&](int m) -> ll
    {
        ll T = 0, ret = 0;

        for (char c : u)
        {
            if (c == 'I')
            {
                if (T < x)
                {
                    T++;
                    ret++;
                }
            }
            else if (c == 'E')
            {
                if (ret < T * s)
                    ret++;
            }
            else
            {
                if (m-- > 0)
                {
                    if (T < x)
                    {
                        T++;
                        ret++;
                    }
                }
                else
                {
                    if (ret < T * s)
                        ret++;
                }
            }
        }

        return ret;
    };

    int l = 0, r = n;
    while (l < r)
    {
        int m = l+(r-l)/2;

        int x = f(m), y = f(m + 1);

        if (x < y)
            l = m + 1;
        else
            r = m;
    }

    cout << f(l) << "\n";
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