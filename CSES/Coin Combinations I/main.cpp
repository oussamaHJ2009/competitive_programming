#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, X;
    cin >> N >> X;
    vector<int> C(N);
    for (int i = 0; i < N; i++)
        cin >> C[i];
    vector<int> dp(X + 1, 0);
    dp[0] = 1;
    int mod=1e9+7;
    for (int i = 1; i <= X; i++)
    {
        for (auto c : C)
        {
            if (i - c >= 0)
                dp[i] += dp[i - c];
            dp[i] %= mod;
        }
    }
    cout << dp[X] << endl;

    return 0;
}