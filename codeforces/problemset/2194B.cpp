#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        ll x, y;
        cin>>n>>x>>y;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)cin>>a[i];
        ll Sall = 0;
        ll ans = -1;
        for (int i = 0; i < n; i++)
        {
            Sall += a[i]/x;
        }
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (Sall - a[i]/x)*y + a[i]);
        }
        cout<<ans<<endl;
    }
}