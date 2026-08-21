#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    ll n,k;
    cin>>n>>k;

    vector<vector<ll>>md(abs(k),vector<ll>());

    for(ll i=0;i<n;i++){
        ll a;cin>>a;
        md[a%k].push_back(a/k);
    }
    ll ans=0;


    for (ll m = 0; m < abs(k); m++)
    {
        sort(md[m].begin(),md[m].end());
        for(ll i=1;i<md[m].size();i++){
            if(md[m][i]<=md[m][i-1]){
                ans+=md[m][i-1]+1-md[m][i];
                md[m][i]+=md[m][i-1]+1-md[m][i];
            }
        }
    }
    
    cout<<ans<<'\n';
}

int main() {
    setIO("");
    ll t = 1;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}