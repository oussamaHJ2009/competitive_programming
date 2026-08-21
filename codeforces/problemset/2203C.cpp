#include<bits/stdc++.h>
#define int long long
using namespace std;
 
bool get(int x, int a, int lim){
	int f = 0;
	for (int i = 59; i >= 0; i--){
		f <<= 1;
		if (((x >> i) & 1) == 1){
			f++;
		} 
		if (((a >> i) & 1) == 1){
			f -= min(lim, f);
		}
	}
	return (f == 0);
}
 
void solve(){
	int x, a;
	cin >> x >> a;
 
	if (!get(x, a, 1ll << 60)){
		cout << -1 << '\n';
		return;
	}
 
	int l = 0, r = (1ll << 60);
	while(l <= r){
		int m = l + (r - l) / 2;
		if (get(x, a, m)){
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
 
	cout << l << '\n';
}
 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int tests = 1;
	cin >> tests;
	for (int test = 0; test < tests; test++){
		solve();
	}
	return 0;
}