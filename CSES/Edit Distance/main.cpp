/* stuff you should look for
 *  int overflow, array bounds
 *  special cases (n=1?)
 *  do smth instead of nothing and stay organized
 *  WRITE STUFF DOWN
 *  DON'T GET STUCK ON ONE APPROACH
 */
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
  string s, t;
  cin >> s >> t;
  vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));
  for (int i = 0; i <= t.size(); i++)
    dp[0][i] = i;
  for (int i = 0; i <= s.size(); i++)
    dp[i][0] = i;
  for (int i = 1; i <= s.size(); i++)
    for (int j = 1; j <= t.size(); j++)
      dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1,
                      dp[i - 1][j - 1] + (s[i - 1] != t[j - 1])});
  cout << dp[s.size()][t.size()] << '\n';
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