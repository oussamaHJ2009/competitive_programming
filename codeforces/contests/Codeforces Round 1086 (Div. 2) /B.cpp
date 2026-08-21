#include<bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll t; cin>>t;
    while(t--){
        ll n,k,p,m;
        cin>>n>>k>>p>>m;
        vector<ll>a(n);
        auto cmp = [](const ll &p1, const ll &p2) {
        return p1 > p2;
    };

        priority_queue<ll, vector<ll>, decltype(cmp)> pq(cmp);
        for (ll i = 0; i < n; i++)
        {
            cin>>a[i];
            if(i<k)pq.push(a[i]);
        }
        
        ll cnt=a[p-1];
        if(p>k){
            int nxt=k;
            cnt+=pq.top();
            pq.pop();
            for (int i = 0; i < p-k-1; i++)
            {
                cnt+=pq.top();
                pq.pop();
                pq.push(a[nxt]);
                nxt++;
            }
        }
        ll fullCycle=a[p-1];
        a[p-1]=m+1;
        sort(a.begin(),a.end());
        for (ll i = 0; i < n-k; i++)
        {
            fullCycle+=a[i];
        }
        ll ans=0;
        while (cnt<=m)
        {
            ans++;
            cnt+=fullCycle;
        }
        cout<<ans<<endl;
    }

    return 0;

}