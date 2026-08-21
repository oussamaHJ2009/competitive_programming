#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin>>N;
    vector<ll>A(N);
    for (int i = 0; i < N; i++)
    {
        cin>>A[i];
    }
    vector<ll>suff(N);
    vector<ll>pref(N);
    pref[0]=A[0];
    suff[N-1]=A[N-1];
    for (int i = 1; i < N; i++)
    {
        pref[i]=gcd(pref[i-1],A[i]);
    }
    for (int i = N-2; i >= 0; i--)
    {
        suff[i]=gcd(suff[i+1], A[i]);
    }
    ll ans = max(pref[N-2], suff[1]);
    for (int i = 1; i < N-1; i++)
    {
        ans = max(ans, gcd(suff[i+1], pref[i-1]));
    }
    cout<<ans<<endl;

    return 0;

}