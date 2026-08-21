#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    k&=1;
    vector<ll>L(n),R(n);
    for (int i = 0; i < n; i++)
    {
        L[i]=(i && L[i-1]>0 ? L[i-1] : 0LL)+a[i];
    }
    for (int i = n-1; i >= 0; i--)
    {
        R[i]=(i<n-1 && R[i+1]>0 ? R[i+1] : 0LL)+a[i];
    }
    ll ans=LONG_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,L[i]+R[i]-a[i]+b[i]*k);
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