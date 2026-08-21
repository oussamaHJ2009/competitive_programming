#include<bits/stdc++.h>
using namespace std;
const int mxn=2e5+5;
set<int>s;
map<int,int>u;
int n,a[mxn],k;
void solve(){
	s.clear(),u.clear();
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],s.insert(a[i]),u[a[i]]=1;
	vector<int>ans;ans.clear();
	while(s.size()){
		int t=*s.begin();
		ans.push_back(t);
		s.erase(s.begin());
		for(int cur=t;cur<=k;cur+=t){
			if(!u[cur]){
				cout<<"-1\n";
				return;
			}
			auto t=s.find(cur);
			if(t!=s.end())s.erase(t);
		}
	}
	cout<<ans.size()<<'\n';
	for(int i:ans)cout<<i<<' ';cout<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
	cin>>T;
	for(;T--;)solve();
	return 0;
}