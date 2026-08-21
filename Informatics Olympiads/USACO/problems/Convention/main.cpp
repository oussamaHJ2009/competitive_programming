#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    
    ll N,M,C;
    cin>>N>>M>>C;
    vector<ll>T(N);
    for (ll i = 0; i < N; i++)
    {
        cin>>T[i];
    }
    sort(T.begin(),T.end());
    ll lo = 0, hi=1e9;
    ll ans = 67;
    while (lo<=hi)
    {
        ll mid = lo+(hi-lo)/2;
        //cerr<<"take with x="<<mid<<endl;
        ll cur=1, cnt=1, last=0;
        for (ll i = 1; i < N; i++)
        {
            //cerr<<"take"<<i<<" : ";
            if(T[i]-T[last]<=mid && cur<C){
                //cerr<<"yes"<<", ";
                cur++;
            }
            else{
                cnt++;
                last=i;
                cur=1;
                //cerr<<"no"<<", ";
            }
        }
        if(cnt<=M){
            hi = mid-1;
            ans=mid;
            //cerr<<"hi=mid-1"<<endl;
        }else{
            lo = mid+1;
            //cerr<<"lo=mid+1"<<endl;
        }
    }
    cout<<ans<<endl;

    return 0;

}