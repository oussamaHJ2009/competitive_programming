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
        ll s, m;
        cin>>s>>m;
        if(m%2 == 0 && s%2==1)cout<< -1 <<endl;
        else{
            auto check = [&](ll n){
                ll a = s/n;
                ll mod = s%n;
                map<ll,ll> cnt;
                if(a&m!=a)return false;
                for (int i = 1; i <= mod; i++)
                {
                    if((a+i)&m == a+i && mod%i==0){
                        
                    }
                }
                
            };
        }
    }
    

    return 0;

}