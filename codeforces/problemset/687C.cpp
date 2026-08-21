#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
	int n,k;
	cin>>n>>k;
	vector<int>c(n);
	for (int i = 0; i < n; i++)
	{
		cin>>c[i];
	}
	vector<vector<int>>dp(k+1,vector<int>(k+1,0));
	dp[0][0]=1;
	for(auto v:c){
		for (int i = k; i >= v; i--)
		{
			for (int j=i;j>=0;j--)
			{
				dp[i][j]|=dp[i-v][j];
				if(j>=v) dp[i][j]|=dp[i-v][j-v];
			}
		}
	}
	set<int>res;
	for (int i = 0; i <= k; i++)
	{
		if(dp[k][i])res.insert(i);
	}
	cout<<res.size()<<'\n';
	for (auto x:res)
	{
		cout<<x<<' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	// cin >> t;
	
	while (t--) {
		solve();
	}
	
	return 0;
}