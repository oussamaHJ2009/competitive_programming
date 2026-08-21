//problem link: https://atcoder.jp/contests/abc466/tasks/abc466_e
//authored by a human (i guess?)


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<ll>A(n),B(n),D(n);
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        cin>>A[i]>>B[i];
        D[i]=B[i]-A[i];
        cerr<<D[i]<<' ';
        ans+=A[i];
    }
    priority_queue<ll>pq;
    ll cur=0;
    for (int i = 0; i < n; i++)
    {
        if(D[i]>0)cur+=D[i];
        else{
            if(cur)pq.push(cur);
            cur=0;
        }
    }
    
    for (int i = 0; i < k && !pq.empty(); i++)
    {
        ans+=pq.top();pq.pop();
    }
    
    
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}