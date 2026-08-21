#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353

void dfs(vector<vector<int>> &adj, vector<int> &id, int cnt, int cur)
{
    if (id[cur] != -1)
        return;
    id[cur] = cnt;
    for (auto u : adj[cur])
    {
        dfs(adj, id, cnt, u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m1, m2;
        cin >> n >> m1 >> m2;
        vector<vector<int>> G(n);
        vector<int> idG(n, -1);
        vector<vector<int>> F(n);
        vector<int> idF(n, -1);
        vector<pair<int, int>> E(m1);
        int cntG = 0, cntF = 0;
        //taking nodes of F
        for (int i = 0; i < m1; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            E[i] = {a, b};
        }
        //taking input of G
        for (int i = 0; i < m2; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        //dfs over G:
        for (int i = 0; i < n; i++)
        {
            if (idG[i] == -1)
            {
                dfs(G, idG, cntG, i);
                cntG++;
            }
        }
        //cecking for bad edges and creating F
        int ans = 0;
        for (int i = 0; i < m1; i++)
        {
            int a = E[i].first, b = E[i].second;
            if (idG[a] != idG[b]){
                ans++;
            }else
            {
                F[a].push_back(b);
                F[b].push_back(a);
            }
        }

        //dfs over F after removing bad edges:
        for (int i = 0; i < n; i++)
        {
            if (idF[i] == -1)
            {
                dfs(F, idF, cntF, i);
                cntF++;
            }
        }
        ans+=cntF-cntG;
        cout << ans << '\n';
    }

    return 0;
}