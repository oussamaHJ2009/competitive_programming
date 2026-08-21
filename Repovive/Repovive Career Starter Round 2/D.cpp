#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    ll s=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    if(s%(n+k)){
        cout<<"No";
        return;
    }
    ll ops=s/(n+k);
    ll cnt=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]-ops<0){
            cout<<"NO";
            return;
        }
        if((a[i]-ops)%k){
            cout<<"NO";
            return;
        }
        cnt+=(a[i]-ops)/k;
    }
    if(cnt!=ops){
        cout<<"NO";
        return;
    }

    cout<<"Yes";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    
    while (t--) {
        solve();
        cout<<'\n';
    }
    
    return 0;
}