#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    ll K;
    cin>>N>>K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        cin>>A[i];
    }
    ll lo = 0, hi = *max_element(A.begin(),A.end());
    ll best=0;
    while (lo<=hi)
    {
        ll mid = lo+(hi-lo)/2;
        ll cur = 0;
        for (int i = 0; i < N; i++)
        {
            cur+=min(A[i], mid);
        }
        if(cur<=K){
            best=mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        K-=min(A[i],best);
        A[i] = max(0LL, A[i]-best);
    }
    
    for (int i = 0; K>0; i++)
    {
        if(A[i%N]>0){
            K--;
            A[i%N]--;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout<<A[i]<<" ";
    }
    
    

    return 0;

}