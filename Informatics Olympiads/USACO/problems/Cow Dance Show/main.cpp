#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    
    int N, T;
    cin>>N>>T;
    vector<int>D(N);
    for (int i = 0; i < N; i++)
    {
        cin>>D[i];
    }
    int lo=1, hi=N;
    int ans=1;
    auto ok = [&](int K){
        priority_queue<int>pq;
        int time=0;
        for (int i = 0; i < K; i++)
        {
            pq.push(-D[i]);
        }
        for (int i = K; i < N; i++)
        {
            time-=min(pq.top()+time,0);
            pq.pop();
            pq.push(-D[i]-time);
        }
        int mx=0;
        while (!pq.empty())
        {
            mx=max(mx,-pq.top());
            pq.pop();
        }
        return (mx <= T);
    };
    //cerr<<"4 case: "<<ok(4)<<endl;

    while (lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        
        if(ok(mid)){
            hi=mid-1;
            ans=mid;
        }else{
            lo=mid+1;
        }
    }
    
    cout<<ans<<endl;
    return 0;

}