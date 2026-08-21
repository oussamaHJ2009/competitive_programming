#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>>task(n);
    for(auto &[a,d]:task){
        cin>>a>>d;
    }
    sort(task.begin(),task.end());
    ll f=0;
    ll ans=0;
    for(auto [a,d]:task){
        f+=a;
        ans+=d-f;
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