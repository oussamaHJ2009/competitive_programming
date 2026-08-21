//problem link: https://atcoder.jp/contests/arc215/tasks/arc215_a
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,k,l;
    cin>>n>>k>>l;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    priority_queue<int>q;
    for (int i = 1; i < n; i++)if(a[i]-a[i-1]>0)q.push((a[i]-a[i-1])/2);
    ll d[2]={a[0],l-a[n-1]};
    ll ans=max(d[0],d[1])+(d[0]+d[1])*(k-1);
    ll cur=0;
    while (!q.empty() && k)
    {
        int b=q.top();
        q.pop();
        cur+=b;
        d[0]+=b;d[1]+=b;
        k--;
        if(k>0){
            ans=max(ans,cur + max(d[0],d[1])+(d[0]+d[1])*(k-1));
        }else ans=max(ans,cur);
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}