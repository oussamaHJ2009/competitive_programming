#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> h_edge(n, vector<int>(m-1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-1; j++)
            cin >> h_edge[i][j];
    
    vector<vector<int>> v_edge(n-1, vector<int>(m));
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < m; j++)
            cin >> v_edge[i][j];
    
    if (k % 2 == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << -1<<" ";
            cout << '\n';
        }
        return 0;
    }
    
    int steps = k / 2;
    vector<vector<ll>> h(n, vector<ll>(m, 0));
    vector<vector<ll>> nh(n, vector<ll>(m));
    
    for (int t = 0; t < steps; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ll best = LLONG_MAX / 2;
                if (j > 0)   best = min(best, (ll)h_edge[i][j-1] + h[i][j-1]);
                if (j < m-1) best = min(best, (ll)h_edge[i][j]   + h[i][j+1]);
                if (i > 0)   best = min(best, (ll)v_edge[i-1][j] + h[i-1][j]);
                if (i < n-1) best = min(best, (ll)v_edge[i][j]   + h[i+1][j]);
                nh[i][j] = best;
            }
        }
        swap(h, nh);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout<< 2 * h[i][j]<<" ";
        cout << '\n';
    }
    return 0;
}