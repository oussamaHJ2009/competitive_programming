#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    
    int N,K;
    cin>>N>>K;
    vector<int>x(N);
    for (int i = 0; i < N; i++)
    {
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    
    int lo=0, hi=x[N-1];
    int ans=x[N-1];
    while (lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        int cnt=1;
        int last=x[0];
        for (int i = 0; i < N; i++)
        {
            if(2*mid<x[i]-last){
                cnt++;
                last=x[i];
            }
        }
        if(cnt<=K){
            hi=mid-1;
            ans=mid;
        }else{
            lo=mid+1;
        }
    }
    
    cout<<ans<<endl;

    return 0;

}