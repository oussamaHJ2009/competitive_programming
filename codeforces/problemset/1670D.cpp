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
    int tc=0;
    while (t--)
    {
        tc++;
        //cerr<<"tc: "<<tc<<endl;
        ll n;
        cin>>n;
        ll lo=2,hi=n;
        ll ans=2;
        while (lo<=hi)
        {
            ll mid=lo+(hi-lo)/2;
            //cerr<<mid<<endl;
            ll a=mid/3, b=mid/3, c=mid/3;
            if(mid%3)a++;
            if(mid%3==2)b++;
            //cerr<<"a = "<<a<<", "<<"b = "<<b<<", "<<"c = "<<c<<endl;
            ll req = (a*b)+(b*c)+(a*c);
            req*=2;
            //cerr<<"req = "<<req<<endl;
            if(req>=n){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        cout<<ans<<endl;
        //cerr<<"new tc"<<endl;
    }
    

    return 0;

}