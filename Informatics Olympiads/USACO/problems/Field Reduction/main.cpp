#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    
    int N;
    cin>>N;
    vector<pair<ll,ll>>cow(N);
    vector<pair<ll,ll>>X(N),Y(N);
    for (int i = 0; i < N; i++)
    {
        ll x,y;
        cin>>x>>y;
        cow[i]={x,y};
        X[i]={x,i};Y[i]={y,i};
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());

    vector<pair<ll,ll>>can;
    vector<bool>put(N,false);
    for (int i = 0; i<N && can.size()<=12; i++)
    {
        if(!put[X[i].second]){can.push_back(cow[X[i].second]);put[X[i].second]=true;}
        if(!put[Y[i].second]){can.push_back(cow[Y[i].second]);put[Y[i].second]=true;}
        if(!put[X[N-i-1].second]){can.push_back(cow[X[N-1-i].second]);put[X[N-i-1].second]=true;}
        if(!put[Y[N-1-i].second]){can.push_back(cow[Y[N-1-i].second]);put[Y[N-1-i].second]=true;}
    }
    ll ans=1e18;
    for (int i = 0; i < can.size(); i++)
    {
        for (int j = i+1; j < can.size(); j++)
        {
            for (int k = j+1; k < can.size(); k++)
            {
                ll mnx=1e18,mny=1e18,mxx=0,mxy=0;
                for (int cur = 0; cur < can.size(); cur++)
                {
                    if(cur!=i&&cur!=j&&cur!=k){
                        mxx=max(mxx,can[cur].first);
                        mnx=min(mnx,can[cur].first);
                        mxy=max(mxy,can[cur].second);
                        mny=min(mny,can[cur].second);
                    }
                }
                ans=min(ans,(mxx-mnx)*(mxy-mny));
            }
            
        }
        
    }
    
    cout<<ans;

    return 0;

}