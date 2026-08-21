#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    for (int i = 0; i < n; i+=2)
    {
        if(i<n-1 && a[i]>a[i+1]){
            ans+=a[i]-a[i+1];
            a[i]=a[i+1];
        }
        if(i>0 && a[i]>a[i-1]){
            ans+=a[i]-a[i-1];
            a[i]=a[i-1];
        }
    }
    for (int i = 1; i < n; i+=2)
    {
        if(i<n-1){
            if(a[i-1]+a[i+1]>a[i]){
                ans+=a[i+1] - (a[i]-a[i-1]);
                a[i+1] = a[i]-a[i-1];
            }
        }
    }
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