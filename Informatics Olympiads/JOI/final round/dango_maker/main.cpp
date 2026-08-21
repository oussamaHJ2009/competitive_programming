#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<string> G(N, string(M, ' '));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> G[i][j];
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            bool ci = (i >= 3 && G[i - 1][j - 1] == 'W' && G[i - 2][j - 1] == 'G' && G[i - 3][j - 1] == 'R'),
                 cj = (j >= 3 && G[i - 1][j - 1] == 'W' && G[i - 1][j - 2] == 'G' && G[i - 1][j - 3] == 'R');
            if (ci)
                dp[i][j] = max(dp[i][j], dp[i - 3][j] + dp[i][j - 1] - dp[i - 1][j - 1] + 1);
            if (cj)
                dp[i][j] = max(dp[i][j], dp[i][j - 3] + dp[i - 1][j] - dp[i - 1][j - 1] + 1);
            if (!cj && !ci)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    cout << dp[N][M] << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}