#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

using ll = long long;

void setIO(string name = "")
{
	cin.tie(0)->sync_with_stdio(0);
	if (!name.empty())
	{
		(void)!freopen((name + ".in").c_str(), "r", stdin);
		(void)!freopen((name + ".out").c_str(), "w", stdout);
	}
}

ll exp(ll a, ll b)
{
	int ret = 1;
	a %= mod;
	while (b > 0)
	{
		if (b & 1)
			ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> s(n), c(n), ind(26, 0);
	vector<int> dp(k + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i] >> c[i];
		c[i]--;
	}
	for (int i = 0; i < m; i++)
	{
		char x;
		cin >> x;
		ind[x - 'A']++;
	}
	for (int j = 1; j <= k; j++)
		for (int i = 0; i < n; i++)
			if(s[i]<=j)(dp[j] += dp[j - s[i]]) %= mod;

	vector<int> C(n, 0);
	for (int i = 0; i < n; i++)
		(C[c[i]] += dp[k - s[i]]) %= mod;

	vector<ll> calc(26, 0);
	ll ans = 1;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < n; j++)
			if (C[j] && ind[i])
				(calc[i] += exp(C[j], ind[i])) %= mod;
		if (calc[i])
			(ans *= calc[i]) %= mod;
	}

	cout << ans << '\n';
}

int main()
{
	setIO("poetry");
	int t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}