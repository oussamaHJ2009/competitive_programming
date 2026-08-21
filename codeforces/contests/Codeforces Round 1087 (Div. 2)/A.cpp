#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        ll n,c,k;
        cin>>n>>c>>k;
        vector<ll>a(n);
        for (int i = 0; i < n; i++) cin>>a[i];
        sort(a.begin(),a.end());
        for (int i = 0; i < n; i++)
        {
            if(a[i]>c)break;
            int x=min(c-a[i],k);
            k-=x;
            c+=a[i]+x;
        }
        cout<<c<<endl;
    }

    return 0;

}