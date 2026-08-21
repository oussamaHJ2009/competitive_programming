#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int q;
    cin>>q;
    vector<ll>cyl={0};
    vector<ll>cs={0};
    ll i=0;
    ll acc=0;
    ll ac=0;
    while (q--)
    {
        int t;cin>>t;
        if(t==1){
            ll c,x;
            cin>>x>>c;
            cs.push_back(c+cs[i]);
            cyl.push_back(x*c+cyl[i]);
            i++;
        }else{
            ll c;
            cin>>c;
            ac+=c;
            ll pt = lower_bound(cs.begin(),cs.end(),ac)-cs.begin();
            ll ans=cyl[pt-1]+(((cyl[pt]-cyl[pt-1])/(cs[pt]-cs[pt-1]))*(-cs[pt-1]+ac))-acc;
            cout<<ans<<endl;
            acc+=ans;
        }
    }
    

    return 0;

}