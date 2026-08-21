#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>d(n+2,0);
    for (int i = 0; i < k; i++)
    {
        int l,r;cin>>l>>r;
        d[l]++;d[r+1]--;
    }

    for (int i = 1; i <= n+1; i++)
    {
        d[i]+=d[i-1];
    }
    sort(d.begin()+1,d.begin()+n+1);
    // for(auto x:d)cerr<<x<<' ';
    cout<<d[(n+1)/2]<<'\n';
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