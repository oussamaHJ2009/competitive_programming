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

void solve()
{
    int S, N;
    cin >> S >> N;

    vector<priority_queue<pair<int, int>>> ibw(S + 1);
    for (int i = 0; i < N; i++)
    {
        int v, w, k;
        cin >> v >> w >> k;
        ibw[w].push({v, k});
    }

    vector<int> dp(S + 1);
    dp[0] = 0;

    for (int w = 1; w <= S; w++)
    {
        int left = S / w;
        while (!ibw[w].empty() && left)
        {
            auto [v, k] = ibw[w].top();
            ibw[w].pop();
            k = min(k, left);
            left -= k;
            while (k--)
                for (int j = S; j >= w; j--)
                    dp[j] = max(dp[j], dp[j - w] + v);
                
        }
    }

    cout << dp[S] << '\n';
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