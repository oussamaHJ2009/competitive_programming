// problem link: https://codeforces.com/contest/1017/problem/D
// written by a rando

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int MAXK = 100;
int n, m, q;

int toint(string x)
{
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == '1')
            ret |= 1 << i;
    }
    return ret;
}

void solve()
{
    cin >> n >> m >> q;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    vector<int> cnt(1 << n, 0);
    for (int i = 0; i < m; i++)
    {
        string x;
        cin >> x;
        cnt[toint(x)]++;
    }

    vector<int> wu(1 << n);
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
                wu[i] += w[j];
        }
    }

    vector<vector<int>> p(1 << n, vector<int>(MAXK + 1, 0));
    for (int b = 0; b < (1 << n); b++)
    {
        int all = (1 << n) - 1;
        for (int j = 0; j < (1 << n); j++)
        {
            int wuh = wu[all ^ b ^ j];
            if (wuh <= MAXK)
                p[b][wuh] += cnt[j];
        }
    }

    for (int b = 0; b < (1 << n); b++)
    {
        for (int i = 1; i <= MAXK; i++)
        {
            p[b][i] += p[b][i - 1];
        }
    }

    while (q--)
    {
        string qry;
        cin >> qry;
        int k;
        cin >> k;
        cout << p[toint(qry)][k] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}