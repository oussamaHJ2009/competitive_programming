#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD2 = 998244353;
const ll MOD1 = 1e9 + 7;
const ll maxN = 2 * 1e5 + 1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll N;
    cin>>N;
    vector<ll>A(N);
    vector<ll>cnt(maxN,0);
    for (int i = 0; i < N; i++)
    {
        cin>>A[i];
        cnt[A[i]]++;
    }
    sort(A.begin(),A.end());
    ll ans=0;
    for (int i = 1; i <= N-2; i++)
    {
        ans+=i*(N-1-i);
    }
    for (int a = 1; a < maxN; a++)
    {
        ll f=0;
        for (ll i = 1; i < cnt[a]-1; i++)
        {
            f+=i*(cnt[a]-1-i);
        }
        ans-=((cnt[a]*(cnt[a]-1))/2)*(N-cnt[a])+f;
    }
    cout<<ans<<endl;
    

    return 0;
}