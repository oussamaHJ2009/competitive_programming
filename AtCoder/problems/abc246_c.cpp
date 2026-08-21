#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n,k,x;
    cin>>n>>k>>x;
    vector<ll>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end(),[&](const int a, const int b){return (a%x > b%x);});
    ll ans=0;
    for (int i = 0; i < n && k; i++)
    {
        int m=min(k,a[i]/x);
        k-=m;
        a[i]-=x*m;
    }
    for (int i = 0; i < n && k; i++)
    {
        a[i]=0;
        k--;
    }
    for (int i = 0; i < n; i++)
    {
        ans+=a[i];
    }
    cout<<ans<<endl;
    
    return 0;

}