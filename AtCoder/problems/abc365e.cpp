//problem link: https://atcoder.jp/contests/abc365/tasks/abc365_e
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll ans=0;
    for(int j=0;j<30;j++){
        vector<int>cnt{1,0};
        int x=(a[0]>>j)&1;
        ll c=0;
        for (int i = 1; i < n; i++)
        {
            int b=(a[i]>>j)&1;
            x^=b;
            c+=cnt[x^1];
            cnt[x^b]++;
        }
        ans+=(1LL<<j)*c;
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