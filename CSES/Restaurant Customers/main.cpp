#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    vector<int>comp;
    for(auto &[x,y]:a){
        cin>>x>>y;
        comp.push_back(x);
        comp.push_back(y);
    }
    sort(comp.begin(),comp.end());
    map<int,int>idx;
    for (int i = 0; i < 2*n; i++)
    {
        idx[comp[i]]=i;
    }
    vector<int>T(2*n+1,0);
    for (auto [s,e]:a)
    {
        T[idx[s]]++;T[idx[e]+1]--;
    }
    int ans=0;
    for (int i = 1; i <= 2*n; i++)
    {
        T[i]+=T[i-1];ans=max(ans,T[i]);
    }
    cout<<ans<<'\n';
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