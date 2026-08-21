#include <bits/stdc++.h>
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

int n;

struct cow
{
    int x, y, id;
};

bool byy(cow a, cow b)
{
    return a.y < b.y;
}

bool byx(cow a, cow b)
{
    return a.x < b.x;
}

vector<int> ans;

void solve()
{
    cin >> n;
    ans.assign(n, 0);
    vector<cow> E, N;
    for (int i = 0; i < n; i++)
    {
        cow cur;
        cur.id = i;
        char c;
        cin >> c;
        cin >> cur.x >> cur.y;
        if (c == 'E')
            E.push_back(cur);
        else
            N.push_back(cur);
    }
    sort(E.begin(), E.end(), byy);
    sort(N.begin(), N.end(), byx);
    vector<bool> b(n, false);
    int nsz = N.size(), esz = E.size();
    for (int i = 0; i < nsz; i++)
    {
        for (int j = 0; j < esz; j++)
        {
            if (E[j].y < N[i].y || E[j].x > N[i].x || N[i].x - E[j].x == E[j].y - N[i].y || b[E[j].id])
            {
                continue;
            }
            else if (N[i].x - E[j].x > E[j].y - N[i].y)
            {
                ans[N[i].id] += ans[E[j].id] + 1;
                b[E[j].id] = true;
            }
            else if (N[i].x - E[j].x < E[j].y - N[i].y)
            {
                ans[E[j].id] += ans[N[i].id] + 1;
                b[N[i].id] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << '\n';
    }
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