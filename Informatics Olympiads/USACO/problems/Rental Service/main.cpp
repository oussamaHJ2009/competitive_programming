#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    int N,M,R;
    cin>>N>>M>>R;
    vector<int>c(N),r(R);
    vector<pair<int,int>>m(M);
    for (int i = 0; i < N; i++)cin>>c[i];
    for(int i=0;i<M;i++)cin>>m[i].second>>m[i].first;
    for(int i=0;i<R;i++)cin>>r[i];
    sort(r.begin(),r.end());
    sort(c.begin(),c.end(),greater<int>());
    sort(m.begin(),m.end(),greater<pair<int,int>>());

    vector<ll>psm(N+1,0);
    vector<ll>prc(N+2,0);
    int crur=R-1;
    for(int i=N;i>0;i--){
        prc[i]=prc[i+1];
        if(crur>=0)prc[i]+=r[crur];
        crur--;
    }
    int cur=0;
    for(int i=0;i<N;i++){
        while (cur < M && c[i]>m[cur].second)
        {
            psm[i+1]+=m[cur].first*m[cur].second;
            c[i]-=m[cur].second;
            cur++;
        }
        if(cur<M && c[i]>0){
            m[cur].second-=c[i];
            psm[i+1]+=c[i]*m[cur].first;
        }
    }
    for(int i=1;i<=N;i++)psm[i]+=psm[i-1];
    ll ans=0;
    for(int i=0;i<=N;i++)
        ans=max(ans,psm[i]+prc[i+1]);
    cout<<ans<<'\n';
}

int main() {
    setIO("rental");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}