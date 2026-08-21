/*
chose the unoptimal approach
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int>R(N);
        ll ans=0;
        for (int i=0;i<N;i++)
        {
            cin>>R[i];
            ans+=R[i];
        }
        for (int i = 1; i < N; i++)
        {
            R[i]=min(R[i-1]+1,R[i]);
        }
        for (int i = N-2; i >= 0; i--)
        {
            R[i]=min(R[i+1]+1,R[i]);
        }
        for (auto x:R)
        {
            ans-=x;
        }
        
        cout<<ans<<"\n";
    }

    return 0;

}