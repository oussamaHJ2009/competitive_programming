#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

const int MAXN = 1e5 + 5;

void dijk(int s, vector<vector<pair<int, ll>>> &adj, vector<ll> &d)
{
    d[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0LL, s});
    while (!pq.empty())
    {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist > d[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (d[v] > dist + w)
            {
                d[v] = dist + w;
                pq.push({d[v], v});
            }
        }
    }
}

vector<vector<pair<int, ll>>> adj;
vector<bool> insp;
vector<ll> Ud, Vd, Sd, Td;
bool vis[MAXN]{0};
vector<vector<int>> DAG(MAXN);

void buildDAG(int u, ll D)
{
    vis[u] = 1;
    for (auto [v, w] : adj[u])
    {
        if (insp[v] && D + w == Sd[v])
        {
            DAG[u].push_back(v);
            if (!vis[v])
                buildDAG(v, D + w);
        }
    }
}

ll ans;
vector<ll> dpU(MAXN), dpV(MAXN);

void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = 1;
    dpU[u] = Ud[u];
    dpV[u] = Vd[u];
    for (int v : DAG[u])
    {
        dfs(v);
        dpU[u] = min(dpU[u], dpU[v]);
        dpV[u] = min(dpV[u], dpV[v]);
    }

    return;
}

void solve()
{
    int N, M, S, T, U, V;
    cin >> N >> M >> S >> T >> U >> V;
    S--, T--, U--, V--;
    adj.assign(N, vector<pair<int, ll>>());
    insp.assign(N, false);
    Ud.assign(N, INF);
    Vd.assign(N, INF);
    Sd.assign(N, INF);
    Td.assign(N, INF);
    while (M--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dijk(S, adj, Sd);
    dijk(T, adj, Td);
    dijk(U, adj, Ud);
    dijk(V, adj, Vd);

    for (int i = 0; i < N; i++)
    {
        if (Sd[i] + Td[i] == Sd[T])
            insp[i] = 1;
    }

    buildDAG(S, 0LL);

    fill(vis, vis + N, 0);
    vis[T] = 1;
    dpU[T] = Ud[T];
    dpV[T] = Vd[T];
    dfs(S);

    ll ans = Ud[V];

    for (int i = 0; i < N; i++)
    {
        if (insp[i])
            ans = min({ans, Vd[i] + dpU[i], Ud[i] + dpV[i]});
    }

    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}