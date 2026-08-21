//problem link: https://codeforces.com/problemset/problem/2233/C
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<int>open,close;
	for (int i = 0; i < n; i++)
	{
		if(s[i]=='(')open.push_back(i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if(s[i]==')')close.push_back(i);
	}
	
	int min_cost=1e9;
	int best=n;
	for (int x = 0; x <= k; x++)
	{
		if(x>open.size() || k-x>close.size())continue;
		vector<bool>rm(n,0);
		for (int i = 0; i < x; i++)rm[open[i]]=1;
		for (int i = 0; i < k-x; i++)rm[close[i]]=1;
		int cnt=0;
		int cost=0;
		for (int i = 0; i < n; i++)
		{
			if(rm[i])continue;
			if(s[i]=='(')cnt++;
			else {
				if(cnt>0){
					cnt--;
					cost+=2;
				}
			}
		}
		if(cost<min_cost){
			min_cost=cost;
			best=x;
		}
	}
	string ans(n,'0');
	for (int i = 0; i < best; i++)ans[open[i]]='1';
	for (int i = 0; i < k-best; i++)ans[close[i]]='1';
	cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}