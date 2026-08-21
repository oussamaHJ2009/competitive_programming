#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    
    int N,M;
    cin>>N>>M;
    vector<pair<ll,ll>>lim(M);
    for (int i = 0; i < M; i++)
    {
        cin>>lim[i].first>>lim[i].second;
    }
    sort(lim.begin(),lim.end());
    ll lo=1,hi=lim[M-1].second;
    ll ans=0;
    auto ok = [&](ll D){
        int cnt=0;
        ll last=0;
        for (int i = 0; i < M; i++)
        {
            if(last<lim[i].first)last=lim[i].first;
            while(last<=lim[i].second){
                cnt++;
                last+=D;
            }
        }
        return cnt>=N;
    };
    
    while (lo<=hi)
    {
        ll mid=lo+(hi-lo)/2;
        if(ok(mid)){
            ans=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    
    cout<<ans<<endl;

    return 0;

}