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
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        ll lo = a[0], hi =a[1];
        ll k = a[0];
        while (lo < hi)
        {
            ll mid = lo + (hi - lo)/2;
            if(a[1] - mid >= a[0]%mid){
                k = mid;
                lo = mid + 1;
            }else{
                hi = mid-1;
            }
        }
        cout<<k<<endl;
        
    }
    

    return 0;

}