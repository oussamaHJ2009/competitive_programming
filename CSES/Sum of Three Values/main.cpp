#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
	ll n,x;
	cin>>n>>x;
	vector<pair<ll,ll>>a(n);
	for (ll i = 0; i < n; i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a.begin(),a.end());
	vector<ll>v;
	for (ll i = 0; i < n; i++)
	{
		v.push_back(a[i].first);
	}
	
	for (ll i = 0; i < n; i++)
	{
		for (ll j = i+1; j < n; j++)
		{
			ll k=lower_bound(v.begin(),v.end(),x-v[i]-v[j])-v.begin();
			if(k!=n && k!=i && k!=j && v[k]+v[i]+v[j]==x){
				cout<<a[i].second+1<<' '<<a[j].second+1<<' '<<a[k].second+1;
				return;
			}
		}
	}
	cout<<"IMPOSSIBLE";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll t = 1;
	// cin >> t;
	
	while (t--) {
		solve();
	}
	
	return 0;
}