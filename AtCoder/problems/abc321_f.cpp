#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int dp[5001] = {1};

int main()
{
  int q, k;
  cin >> q >> k;
  while (q--)
  {
    char c;
    int x;
    cin >> c >> x;
    if (c == '+')
      for (int j = k; j >= x; j--)
        (dp[j] += dp[j - x])%=mod;
    else
      for (int j = x; j <= k; j++)
        (dp[j] += mod - dp[j - x])%=mod;

    cout << dp[k] << '\n';
  }
}