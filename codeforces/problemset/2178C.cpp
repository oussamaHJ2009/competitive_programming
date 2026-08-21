#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<ll> a(n+1);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }
        vector<ll> pref(n+1);
        pref[0]=0;
        pref[n]=0;
        pref[1]=a[1];
        for (int i = 2; i < n; i++)
        {
            pref[i]=pref[i-1]+ abs(a[i]);
        }
        vector<ll> suf(n+1);
        suf[n]=a[n];
        suf[1]=0;
        for (int i = n-1; i > 1; i--)
        {
            suf[i] = suf[i+1]+a[i];
        }
        ll x= max(-suf[2], pref[n-1]);
        for (int i = 2; i < n; i++)
        {
            x=max(pref[i-1]-suf[i+1], x);
        }
        
        
        
        cout<<x<<endl;
        

    }
    

    return 0;

}
