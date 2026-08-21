#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353
const int maxN = 4 * 1e4 + 1;
int dp[maxN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    set<int> pal;
    for (int i = 1; i < maxN; i++)
    {
        int cur = i;
        string x = "";
        while (cur > 0)
        {
            x += '0' + (cur % 10);
            cur /= 10;
        }
        bool ok = true;
        int sz = x.size();
        for (int j = 0; j < sz / 2 && ok; j++)
        {
            if (x[j] != x[sz - 1 - j])
                ok = false;
        }
        if (ok || sz == 1)
            pal.insert(i);
        dp[0] = 1;
    }
    for (auto p : pal)
    {
        for (int i = 1; i < maxN; i++)
        {
            if (p <= i)
                dp[i] += dp[i - p];
            dp[i] %= mod;
        }
    }
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}