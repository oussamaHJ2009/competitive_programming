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
        int n, h, k;
        cin>>n>>h>>k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        vector<ll> pref(n + 1);
        pref[0]=0;
        for (int i = 0; i < n; i++)
        {
            pref[i+1]=a[i]+pref[i];
        }
        int d = h % pref[n];
        int m = h / pref[n];
        auto pt = lower_bound(pref.begin(), pref.end(), d);
        int xbul = pt - pref.begin();
        if(xbul > 0){

            int ii = 0, ij = 0;
            for (int i = 0; i < xbul; i++)
            {
                if(a[ii] < a[i]) ii = i;
            }
            for (int i = ii+1; i < n; i++)
            {
                if(a[ij] > a[i]) ij = i;
            }
            if(a[ii] < a[ij]){
                ll w = a[ii];
                a[ii] = a[ij];
                a[ij] = w;
                for (int i = 0; i <= n; i++)
                {
                    pref[i] = 0;
                }
                for (int i = 0; i < n; i++)
                {
                    pref[i + 1] = pref[i]+a[i];
                }
                int d = h % pref[n];
                m = h / pref[n];
                pt = lower_bound(pref.begin(), pref.end(), d);
                xbul = pt - pref.begin();
            }
            
        }
        ll ans = m * (n + k) - k;
        if(xbul > 0) ans += xbul + k;
        cout<<ans<<endl;

    }
    

    return 0;

}