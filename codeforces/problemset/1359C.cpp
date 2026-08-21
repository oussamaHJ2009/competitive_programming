#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T_; cin>>T_;
    while(T_--){
        double h,c,t;
        cin>>h>>c>>t;
        int val=0;
        auto f=[&](int x){
            ll num=(x+1)*h+x*c;
            ll denum=2*x+1;
            return num>=denum*t;
        };
        if(2*t<=h+c){
            cout<<2<<"\n";
            continue;
        }
        ll lo=0,hi=INT32_MAX;
        while (lo<=hi)
        {
            ll n=lo+(hi-lo)/2;
            if(f(n)){
                val=n;
                lo=n+1;
            }else{
                hi=n-1;
            }
        }
        ll num1=abs((val+1)*h+val*c - t*(2*val+1));
        ll denum1=2*val+1;
        ll num2=abs((val+2)*h+(val+1)*c - t*(2*val+3));
        ll denum2=2*val+3;
        if(num1*denum2<=num2*denum1){
            cout<<2*val+1<<"\n";
        }else{
            cout<<2*val+3<<"\n";
        }
    }

    return 0;

}