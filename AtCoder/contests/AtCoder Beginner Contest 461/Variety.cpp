#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int N, M, K;
    cin >> N >> K >> M;
    vector<pair<int, int>> G(N);
    for (auto &[x, y] : G)
    {
        cin >> y >> x;
    }
    sort(G.begin(), G.end(), greater<pair<int, int>>());
    vector<int> cnt(N + 1, 0);
    vector<bool> chosen(N);
    ll val=0;
    for (int i = 0; i < N && M > 0; i++)
    {

        if (cnt[G[i].second] == 0)
        {
            cnt[G[i].second]++;
            chosen[i]=1;
            M--;
            K--;
            val+=G[i].first;
        }
    }
    for (int i = 0; i < N && K > 0; i++)
    {

        if (!chosen[i])
        {
            cnt[G[i].second]++;
            chosen[i]=1;
            K--;
            val+=G[i].first;
        }
    }
    cout<<val<<'\n';
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