#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;ll K;
    cin>>N>>K;
    vector<ll>A(N);
    for (int i = 0; i < N; i++)
    {
        cin>>A[i];
    }
    ll ans = 0;
    ll lo = 0;
    ll hi =1e18/K;
    while (lo<=hi)
    {
        ll mid=lo+(hi-lo)/2;
        ll sum=0;
        for (auto x:A)sum+=min(x,mid);
        if(sum>=K*mid){
            lo = mid+1;
            ans=mid;
        }else{
            hi = mid-1;
        }
    }
    

    cout<<ans<<endl;


    return 0;

}