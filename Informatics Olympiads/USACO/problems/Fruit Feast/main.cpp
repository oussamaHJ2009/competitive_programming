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
	int T, A, B;
	cin >> T >> A >> B;
	vector<vector<bool>> dp(T+1, vector<bool>(2));
	dp[0][0] = true;
	for (int f = 1; f <= T; f++)
	{
		if (A <= f)
			dp[f][0] = dp[f - A][0] || dp[f][0];
		if (B <= f)
			dp[f][0] = dp[f - B][0] || dp[f][0];
		dp[f / 2][1] = dp[f / 2][1] || dp[f][0];
	}
	for (int f = 1; f <= T; f++)
	{
		if (A <= f)
			dp[f][1] = dp[f - A][1] || dp[f][1];
		if (B <= f)
			dp[f][1] = dp[f - B][1] || dp[f][1];
	}
	int ans=T;
	while(!(dp[ans][0]||dp[ans][1]))ans--;
	cout<<ans<<'\n';
}

int main()
{
	setIO("feast");
	int t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}