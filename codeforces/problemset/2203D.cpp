#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        map<int, int> cnt;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        vector<int> c(n + m + 1);
        for (int i = 1; i <= n + m; i++)
        {
            for (int j = 1; i * j <= n + m; j++)
            {
                if(i*j <= n+m)c[i * j] += cnt[i];
            }
        }
        int alice = 0, bob = 0, both = 0;
        for (int i = 0; i < m; i++)
        {
            if(c[b[i]] == n)alice++;
            if(c[b[i]] == 0)bob++;
            if(c[b[i]] != n && c[b[i]] != 0)both++;
        }
        if(alice+(both - both/2) > bob+both/2)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }

    return 0;
}