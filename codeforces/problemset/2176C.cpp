#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<ll>even;
    ll max_odd=-1;
    int cnt_odd=0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin>>x;
        if(x&1){
            cnt_odd++;
            max_odd=max(max_odd,x);
        }else{
            even.push_back(x);
        }
    }
    int m=even.size();
    sort(even.rbegin(),even.rend());
    vector<ll>pref(m+1,0);
    for (int i = 1; i <= m; i++)
    {
        pref[i]=pref[i-1]+even[i-1];
    }
    for (int k = 1; k <= n; k++)
    {
        if(cnt_odd==0){
            cout<<0<<' ';
            continue;
        }
        int L=max(1,k-m);
        int R=min(k,cnt_odd);
        int O=L;
        O+=(L&1)^1;
        if(O<=R){
            cout<<max_odd+pref[k-O]<<' ';
        }else{
            cout<<0<<' ';
        }
    }
    cout<<'\n';
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