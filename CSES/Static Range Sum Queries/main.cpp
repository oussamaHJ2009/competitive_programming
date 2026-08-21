#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,q;
    cin>>n>>q;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++){cin>>a[i];a[i]+=a[i-1];}
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<'\n';
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