#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    ll K;
    cin>>N>>K;
    vector<ll>A(N);
    for (int i = 0; i < N; i++)
    {
        cin>>A[i];
    }
    ll lo=1,hi=A[0]+K+1;
    ll ans=0;
    while (lo<=hi)
    {
        ll mid=lo+(hi-lo)/2;
        ll cnt=0;
        for (int i = 0; i < N && cnt<=K; i++)
        {
            if(A[i]<mid)cnt+=(mid-A[i]+i)/(i+1);
        }
        if(cnt<=K){
            ans=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    cout<<ans<<endl;

    return 0;

}