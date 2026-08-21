#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll N;
        cin >> N;
        vector<ll> A(N);
        vector<ll>B(N);
        for (ll i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        for (ll i = 0; i < N; i++)
        {
            cin >> B[i];
        }
        ll ans=0;
        ll x = gcd(A[0],A[1]);
        while (x<B[0])
        {
            if(gcd(x,A[1]) == gcd(A[0],A[1]) && x!=A[0]){
                break;
                ans++;
            }
            x+=gcd(A[0],A[1]);
        }
        x=gcd(A[N-2],A[N-1]);
        while (x<B[N-1])
        {
            if(gcd(x,A[N-2]) == gcd(A[N-1],A[N-2]) && x!=A[N-1]){
                break;
                ans++;
            }
            x+=gcd(A[N-2],A[N-1]);
        }
        
        for (ll i = 1; i < N-1; i++)
        {
            ll a = gcd(A[i],A[i-1]);
            ll b = gcd(A[i],A[i+1]);
            ll l = lcm(a,b);
            x=l;
            while (x<B[i])
            {
                if(gcd(x,A[i-1]) == a && b== gcd(x,A[i+1]) && x!=A[i]){
                break;
                ans++;
            }
                x+=l;
            }
            
        }
        cout<<ans<<endl;
        
    }

    return 0;
}