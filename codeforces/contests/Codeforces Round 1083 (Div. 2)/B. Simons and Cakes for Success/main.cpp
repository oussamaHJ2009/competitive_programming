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
        ll n;
        cin>>n;
        ll ans = 1;
        if(n%2==0)ans*=2;
        while (n%2==0){
            n/=2;
        }
        for (ll i = 3; i*i<= n; i+=2)
        {
            if(n % i == 0)ans*=i;
            while (n%i==0)
            {
                n/=i;
            }
        }
        ans*=n;
        cout<<ans<<endl;
    }
    

    return 0;

}