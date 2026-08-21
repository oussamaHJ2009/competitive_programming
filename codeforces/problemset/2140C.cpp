#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<ll>a(n);
    ll f=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        f+=a[i]*(i&1?-1:1);
    }
    ll odd = -1e18;
    ll even = 1e18;
    ll v1 = f;

    for (int i = 0; i < n; i++)
    {
        if(i%2){
            odd = max(odd,2*a[i]-i);
            v1=max(v1,f-even+2*a[i]+i);
        }else{
            even=min(even,2*a[i]+i);
            v1=max(v1,f+odd-2*a[i]+i);
        }
    }
    
    ll v2 = f + (n > 1 ? n - 2 + n % 2 : 0);
    cout << max(v1, v2) << '\n';
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